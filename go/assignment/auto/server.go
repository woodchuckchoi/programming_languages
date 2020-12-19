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
	configFile = "./config.json"
)

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
		healthChecker := []chan chan struct{}{}
		asyncFunctions := []func(<-chan chan struct{}){a.DBRetreiver, a.RequestSolver}
		for i := 0; i < len(asyncFunctions); i++ {
			checker := make(chan chan struct{})
			go asyncFunctions[i](checker)
			healthChecker = append(healthChecker, checker)
		}

		// for _, hcChannel := { // channel in channel

		// }
	}()

	addr := fmt.Sprintf("%v:%v", a.Conf.ServerIP, a.Conf.ServerPORT)
	a.Server.Logger.Fatal(a.Server.Start(addr))
}

func (a *AutoCompleteServer) DBRetreiver(heartbeat <-chan chan struct{}) {
	select {
	case hcChannel := <-heartbeat:
		hcChannel <- struct{}{}

	case <-time.After(5 * time.Minute):
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
		if !reflect.DeepEqual(data, a.Auto.Words) {
			a.Auto.Words = data
			refreshed := a.Auto.Refresh()
			a.Auto = refreshed
		}
	}
}

func (a *AutoCompleteServer) RequestSolver(heartbeat <-chan chan struct{}) {
	select {
	case req := <-a.RequestPool:
		go func(r Request) {
			req.ResponseChannel <- a.Auto.RetreiveWords(req.SearchString)
			close(req.ResponseChannel)
		}(req)
	case hcChannel := <-heartbeat:
		hcChannel <- struct{}{}
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
	a.Server.GET("/autocomplete/", a.AutoCompleteHandler)
}

func (a *AutoCompleteServer) AutoCompleteHandler(c echo.Context) error {
	searchString := c.FormValue("search_string")
	if searchString == "" {
		return c.NoContent(http.StatusBadRequest)
	}

	respChan := make(chan []string)
	req := Request{
		SearchString:    searchString,
		ResponseChannel: respChan,
	}

	a.RequestPool <- req

	go func(req Request, c echo.Context) error {
		select {
		case ret := <-req.ResponseChannel:
			resp := Response{
				AutoComplete: ret,
			}
			return c.JSON(http.StatusOK, resp)
		case <-time.After(1 * time.Second):
			return c.NoContent(http.StatusRequestTimeout)
		}
	}(req, c)

	return nil
}
