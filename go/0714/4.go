package main

import "fmt"

func factorial(n int) int {
	ret := 1
	for n >= 1 {
		ret *= n
		n--
	}
	return ret
}

func main() {
	fmt.Printf("%v\n", factorial(5))
}
