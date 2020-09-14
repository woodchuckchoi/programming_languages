package main

import (
	"fmt"
)

func main() {
	test := [][]int{}
	for i:=0; i < 10; i++ {
		toAdd := []int{}
		for j:=0; j < 10; j++ {
			toAdd = append(toAdd, j)
		}
		test = append(test, toAdd)
	}

	for i:=0;i<10;i++ {
		fmt.Println(test[i])
	}
}
