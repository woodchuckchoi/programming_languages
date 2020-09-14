package main

import (
	"fmt"
	"runtime"
	"sync"
)

func main() {
	runtime.GOMAXPROCS(runtime.NumCPU())

	var mutex = new(sync.Mutex)
	var cond  = sync.NewCond(mutex)

	c := make(chan bool, 3)

	for i := 0; i < 3; i++ {
		go func(n int) {
			mutex.Lock()
			c <- true
			fmt.Println("wait begin: ", n)
			cond.Wait()
			fmt.Println("wait end: ", n)
			mutex.Unlock()
		}(i)
	}

	for i := 0; i < 3; i++ {
		<- c
	}

	
	mutex.Lock()
	fmt.Println("broadcast")
	// cond.Signal() wakes up one go func
	cond.Broadcast() // wakes up all go funcs
	mutex.Unlock()


	fmt.Scanln()
}