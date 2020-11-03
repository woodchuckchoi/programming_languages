package main

import (
	"fmt"
	"time"
)

func main() {
	recv := make(chan int)
	send := make(chan int)

	select {
	case n := <-recv:
		fmt.Println(n)
	case send <- 1:
		fmt.Println("sent 1")
	case <-time.After(5 * time.Second):
		fmt.Println("No send and receive communication for 5 seconds")
		return
	}
}
