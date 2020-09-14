package main

import (
	"fmt"
)

type MyInt int

func (i MyInt) Print() {
	fmt.Println(i)
}

type Rectangle struct {
	width, height int
}

func (r Rectangle) Print() {
	fmt.Println(r.width, r.height)
}

type Printer interface {
	Print()
}

func main() {
	var i MyInt = 5
	r := Rectangle{width:10, height:20}

	var p Printer

	p = i
	p.Print()

	p = r
	p.Print()
}