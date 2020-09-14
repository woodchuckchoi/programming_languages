package main

import (
	"fmt"
	"time"
)

func main() {
	done := make(chan bool)
	count := 3

	go func() {
		for i := 0; i < count; i++ {
			done <- true
			fmt.Println("Goroutine: ", i)
			time.Sleep(time.Second)
		}
	}()

	for i := 0; i < count; i++ {
		<- done
		fmt.Println("Main function: ", i)
	}
}