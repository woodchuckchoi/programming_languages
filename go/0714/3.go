package main

import "fmt"

func factorial(n int) int {
	ret := 1
	for i:=2;i<=n;i++ {
		ret *= i
	}
	return ret
}

func main() {
	fmt.Println(factorial(5))
}
