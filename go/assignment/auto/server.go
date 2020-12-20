package auto

import (
	"database/sql"
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"os"
	"reflect"
	"sort"
	"time"

	_ "github.com/go-sql-driver/mysql"
	"github.com/labstack/echo/v4"
)

const (
	configFile               = "./config.json"
	timeOutInterval          = 1 * time.Second
	healthCheckInterval      = 5 * time.Minute
	healthCheckGraceInterval = 5 * time.Minute
	refreshInterval          = 10 * time.Minute
)

type Search struct {
	SearchString string `json:"search_string"`
}

type Request struct {
	SearchString    string
	ResponseChannel chan []string
}

type Response struct {
	AutoComplete []string `json:"autocomplete"`
}

type Config struct {
	ServerIP   string   `json:"server_ip"`
	ServerPORT int      `json:"server_port"`
	DBIP       string   `json:"db_ip"`
	DBPORT     int      `json:"db_port"`
	DBUsr      string   `json:"db_usr"`
	DBPass     string   `json:"db_pass"`
	DBName     string   `json:"db_name"`
	Queries    []string `json:"queries"`
}

type AutoCompleteServer struct {
	Server      *echo.Echo
	Auto        *AutoCompleter
	RequestPool chan Request
	Conf        Config
	DBCon       *sql.DB
	Update      chan []chan struct{}
}

func InitialiseAutoCompleteServer() *AutoCompleteServer {
	autoServer := &AutoCompleteServer{
		Server:      echo.New(),
		Auto:        InitialiseAutoCompleter(),
		RequestPool: make(chan Request, 1000),
		Conf:        Config{},
		DBCon:       nil,
	}

	autoServer.ImportConfig()
	autoServer.Route()

	dbUri := fmt.Sprintf("%v:%v@tcp(%v:%v)/%v?charset=utf8mb4",
		autoServer.Conf.DBUsr, autoServer.Conf.DBPass, autoServer.Conf.DBIP,
		autoServer.Conf.DBPORT, autoServer.Conf.DBName,
	)
	db, err := sql.Open("mysql", dbUri)
	if err != nil {
		log.Fatal(err)
	}
	autoServer.DBCon = db

	return autoServer
}

func (a *AutoCompleteServer) Run() {
	go func() {
		asyncFunctions := []func(chan chan<- struct{}){a.DBRetreiver, a.RequestSolver}
		signal := make(chan int, len(asyncFunctions))

		// initialise healthcheck
		for i := 0; i < len(asyncFunctions); i++ {
			hc := make(chan chan<- struct{})
			go keepRunning(asyncFunctions[i], hc, signal, i)
		}

		for {
			select {
			case sig := <-signal:
				hc := make(chan chan<- struct{})
				go keepRunning(asyncFunctions[sig], hc, signal, sig)
			}
		}
	}()

	addr := fmt.Sprintf("%v:%v", a.Conf.ServerIP, a.Conf.ServerPORT)
	a.Server.Logger.Fatal(a.Server.Start(addr))
}

func keepRunning(f func(chan chan<- struct{}), hc chan chan<- struct{}, signal chan<- int, index int) {
	go f(hc)
	isAlive := true

	for isAlive {
		time.Sleep(healthCheckInterval)
		newChan := make(chan struct{})

		select {
		case hc <- newChan:
			select {
			case _, ok := <-newChan:
				if !ok {
					isAlive = false
				}
			case <-time.After(healthCheckGraceInterval):
				isAlive = false
			}

		case <-time.After(healthCheckGraceInterval):
			isAlive = false
		}
	}

	close(hc)
	signal <- index
}

func RetreiveWordsFromDB(a *AutoCompleteServer) []string {
	data := []string{}
	for _, query := range a.Conf.Queries {
		rows, _ := a.DBCon.Query(query)
		defer rows.Close()

		for rows.Next() {
			var academy string
			if err := rows.Scan(&academy); err != nil {
				log.Fatal(err)
			}
			data = append(data, academy)
		}
	}
	sort.Strings(data)
	return data
}

func (a *AutoCompleteServer) DBRetreiver(heartbeat chan chan<- struct{}) {
	a.Auto.Words = RetreiveWordsFromDB(a)
	a.Auto = a.Auto.Refresh()

	for {
		select {
		case hcChannel := <-heartbeat:
			hcChannel <- struct{}{}
			close(hcChannel)

		case <-time.After(refreshInterval):
			data := RetreiveWordsFromDB(a)

			// update notify
			ackChan, finChan := make(chan struct{}), make(chan struct{})
			a.Update <- []chan struct{}{ackChan, finChan}

			select {
			case _ = <-ackChan:
				// update ready
			}

			if !reflect.DeepEqual(data, a.Auto.Words) {
				a.Auto.Words = data
				a.Auto = a.Auto.Refresh()
			}

			// update finished
			finChan <- struct{}{}
			close(finChan)
		}
	}
}

func (a *AutoCompleteServer) RequestSolver(heartbeat chan chan<- struct{}) {
	for {
		select {
		case req := <-a.RequestPool:
			go func(r Request) {
				req.ResponseChannel <- a.Auto.RetreiveWords(req.SearchString)
				close(req.ResponseChannel)
			}(req)

		case hcChannel := <-heartbeat:
			hcChannel <- struct{}{}
			close(hcChannel)

		case needsUpdate := <-a.Update:
			ackChan, finChan := needsUpdate[0], needsUpdate[1]
			// ackChan for notifying DBRetreiver that RequestSolver is on hold for update
			// finChan for receiving from DBRetreiver that update is finished and RequestSolver can work again

			// update ready
			ackChan <- struct{}{}
			close(ackChan)

			// select blocking

			select {
			case _ = <-finChan:
				// update finished
			}
		}
	}
}

func (a *AutoCompleteServer) ImportConfig() {
	f, err := os.Open(configFile)
	if err != nil {
		log.Fatal("Config does not exist!")
	}
	defer f.Close()

	fStat, _ := f.Stat()
	fSize := fStat.Size()

	buffer := make([]byte, fSize)

	numBytes, err := f.Read(buffer)
	if err != nil || int64(numBytes) != fSize {
		log.Fatal("Config is faulty!")
	}

	var conf Config

	err = json.Unmarshal(buffer, &conf)
	if err != nil {
		log.Fatal("Config is faulty!")
	}

	a.Conf = conf
}

func (a *AutoCompleteServer) Route() {
	a.Server.GET("/", func(c echo.Context) error {
		return c.String(200, "test")
	})
	a.Server.POST("/autocomplete", a.AutoCompleteHandler)
}

func (a *AutoCompleteServer) AutoCompleteHandler(c echo.Context) error {
	var searchStringPayload Search
	if err := c.Bind(&searchStringPayload); err != nil || len(searchStringPayload.SearchString) == 0 {
		return c.NoContent(http.StatusBadRequest)
	}
	searchString := searchStringPayload.SearchString

	respChan := make(chan []string)
	req := Request{
		SearchString:    searchString,
		ResponseChannel: respChan,
	}

	a.RequestPool <- req

	select {
	case ret := <-req.ResponseChannel:
		resp := Response{
			AutoComplete: ret,
		}
		return c.JSON(http.StatusOK, resp)
	case <-time.After(timeOutInterval):
		return c.NoContent(http.StatusRequestTimeout)
	}

	// seems like there is no easy way for Echo Framework to handle async calls (context seems to be globally decided)
	// go func(req Request, c echo.Context) error {
	// 	select {
	// 	case ret := <-req.ResponseChannel:
	// 		resp := Response{
	// 			AutoComplete: ret,
	// 		}
	// 		return c.JSON(http.StatusOK, resp)
	// 	case <-time.After(timeOutInterval):
	// 		return c.NoContent(http.StatusRequestTimeout)
	// 	}
	// }(req, c)
	// return nil
}
