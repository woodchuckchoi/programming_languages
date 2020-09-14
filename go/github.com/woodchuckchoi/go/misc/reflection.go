package main

import (
	"reflect"
	"fmt"
)

type Data struct {
	a, b int
}

func main() {
	var num int = 1
	fmt.Println(reflect.TypeOf(num))

	var s string = "Hello, World!"
	fmt.Println(reflect.TypeOf(s))

	var f float32 = 3.14
	fmt.Println(reflect.TypeOf(f))

	var d Data = Data{
		a: 5,
		b: 7,
	}
	fmt.Println(reflect.TypeOf(d))
}