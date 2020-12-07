package server

import (
	"fmt"
	"net/http"

	"github.com/labstack/echo/v4"
	keyvalustore "github.com/woodchuckchoi/assignment/keyvaluestore"
)

var (
	invalidParameterError = setError("INVALID PARAMETER ERROR")
)

type customError struct {
	msg string
}

func setError(s string) customError {
	return customError{
		msg: s,
	}
}

func (e customError) Error() string {
	return e.msg
}

type Response struct {
	Data string `json:"data"`
}

type Server struct {
	Conn     *echo.Echo
	KeyValue *keyvalustore.KeyValueStorage
}

func InitServer() *Server {
	conn := echo.New()

	server := &Server{
		Conn:     conn,
		KeyValue: keyvalustore.InitKeyValueStorage(),
	}

	server.route()
	return server
}

func (s *Server) Start() {
	s.Conn.Logger.Warn(s.Conn.Start(":5000"))
}

func (s *Server) route() {
	s.Conn.POST("/assign", s.assignHandler)
	s.Conn.GET("/get/:key", s.getKeyHandler)
}

func (s *Server) assignHandler(c echo.Context) error {
	type AssignLoad struct {
		Load string `json:"load"`
	}

	Payload := new(AssignLoad)
	if err := c.Bind(Payload); err != nil {
		return err
	}

	s.KeyValue.AssignPartition(Payload.Load)
	if err := s.KeyValue.Process(); err != nil {
		return err
	}
	return c.JSON(http.StatusOK, Response{
		Data: "PAYLOAD RECEIVED",
	})
}

func (s *Server) getKeyHandler(c echo.Context) error {
	key := c.Param("key")
	if len(key) == 0 || key == " " {
		return invalidParameterError
	}

	cnt := s.KeyValue.GetValue(key)

	cntStr := fmt.Sprintf("%v", cnt)

	return c.JSON(http.StatusOK, Response{
		Data: cntStr,
	})
}
