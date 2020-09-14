package main

import "fmt"

func main() {
	s	:= "abc"
	ps	:= &s
	s	+= "def"
	fmt.Println(s)
	fmt.Println(*ps)
}
