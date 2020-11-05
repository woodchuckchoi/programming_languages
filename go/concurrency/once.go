package main

import (
	"fmt"
	"sync"
)

func main() {
	done := make(chan struct{})
	go func() {
		defer close(done)
		fmt.Println("Init")
	}()
	var wg sync.WaitGroup
	for i := 0; i < 3; i++ {
		wg.Add(1)
		go func(i int) {
			defer wg.Done()
			val, ok := <-done
			fmt.Println(val, ok)
			fmt.Println("Goroutine:", i)
		}(i)
	}
	wg.Wait()
}
