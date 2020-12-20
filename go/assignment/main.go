package main

import (
	"github.com/woodchuckchoi/assignment/auto"
)

func main() {
	a := auto.InitialiseAutoCompleteServer()
	a.Run()
}
