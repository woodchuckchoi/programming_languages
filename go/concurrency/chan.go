package main

import "fmt"

func Example_channel() {
	c := func() <-chan int {
		c := make(chan int)
		go func() {
			defer close(c)
			c <- 1
			c <- 2
			c <- 3
		}()
		return c
	}()
	for num := range c {
		fmt.Println(num)
	}
}
func Example_simpleChannel() {
	c := make(chan int)
	go func() {
		c <- 1
		c <- 2
		c <- 3
		close(c)
	}()

	for num := range c {
		fmt.Println(num)
	}
}

func main() {
	Example_channel()
}
