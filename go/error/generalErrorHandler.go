package main

import (
	"fmt"
	"os"
)

func ErrHandler(rets []interface{}) []interface{} {
	if rets[len(rets)-1] != nil {
		fmt.Println(rets[len(rets)-1])
		os.Exit(1)
	}

	return rets[:len(rets)-1]
}

func main() {
	rets := ErrHandler([]interface{}{"test", -123, 0b1011, 636.12, 12 + 3i, nil})
	for i := 0; i < len(rets); i++ {
		to_str := fmt.Sprintf("%v", rets[i])
		fmt.Printf("Value: %-10v, Type: %-10T\n", to_str, rets[i])
	}
	return
}
