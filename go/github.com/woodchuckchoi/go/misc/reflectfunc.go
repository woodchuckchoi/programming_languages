package main

import (
	"fmt"
	"reflect"
)

func h(args []reflect.Value) []reflect.Value {
	fmt.Println("Hello, World!")
	return nil
}

func main() {
	var hello func()

	
}