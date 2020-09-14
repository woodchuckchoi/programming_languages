package main

import (
	"fmt"
)

type Hyuck struct {
	Name	string
	Desc	string
}

func (h *Hyuck)Edit(n string, d string) {
	h.Name	= n
	h.Desc	= d
}

func (h *Hyuck)Print() {
	fmt.Printf("My name is %v and %v.\n", h.Name, h.Desc)
}

var h = Hyuck{
	Name: "Woodchuck",
	Desc: "I wonder why Golang has this \"pointer == variable\" feature",
}

func main() {
	h.Print()
	h.Edit("Roy", "I want to know the answer of that, too")
	h.Print()
}
