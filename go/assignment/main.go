package main

import (
	"github.com/woodchuckchoi/assignment/server"
)

func main() {
	s := server.InitServer()
	s.Start()
}
