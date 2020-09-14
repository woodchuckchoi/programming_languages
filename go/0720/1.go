package main

import (
	"fmt"
)

func main() {
	temp := []byte{}
	temp = append(temp, 'h')
	temp = append(temp, 'i')
	fmt.Println(string(temp))
}
