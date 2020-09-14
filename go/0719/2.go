package main

import (
	"fmt"
)

var str string = "This is the end"

func main() {
	for _, v := range str {
		fmt.Println(string(v))
	}
}
