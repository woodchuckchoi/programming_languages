package main

import "fmt"

func Fibonacci(max int) <-chan int {
	c := make(chan int)
	go func() {
		defer close(c)
		a, b := 0, 1
		for a <= max {
			c <- a
			a, b = b, a+b
		}
	}()
	return c
}

func ExampleFibonacci() {
	for fib := range Fibonacci(15) {
		fmt.Print(fib, ",")
	}
}

func main() {
	ExampleFibonacci()
}
