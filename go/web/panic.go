package main

import (
	"fmt"
)

func f() (i int) {
	i = 10
	defer func() {
		if r := recover(); r != nil {
			fmt.Println("Recovered from ", r)
			i = 100
		}
	}()
	g()
	return 100
}

func g() {
	panic("Panic!")
}

func main() {
	fmt.Println(f())
}
