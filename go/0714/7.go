package main

import "fmt"

func Fibonacci(n int) int {
	p, q := 0, 1

	for n > 1 {
		p, q = q, p+q
		n--
	}
	return p
}

func main() {
	fmt.Println("10th Fibonacci number is ", Fibonacci(10))
}
