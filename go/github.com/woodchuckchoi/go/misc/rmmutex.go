package main

import (
	"fmt"
	"runtime"
	"time"
	"sync"
)

func main() {
	runtime.GOMAXPROCS(runtime.NumCPU())

	var data int = 0
	var rmMutex = new(sync.RWMutex)

	go func() {
		for i := 0; i < 3; i++ {
			rmMutex.Lock()
			data += 1
			fmt.Println("write:", data)
			time.Sleep(10 * time.Millisecond)
			rmMutex.Unlock()
		}
	}()

	go func() {
		for i := 0; i < 3; i++ {
			rmMutex.RLock()
			fmt.Println("read 1:", data)
			time.Sleep(time.Second)
			rmMutex.RUnlock()
		}
	}()

	go func() {
		for i := 0; i < 3; i++ {
			rmMutex.RLock()
			fmt.Println("read 2:", data)
			time.Sleep(2 * time.Second)
			rmMutex.RUnlock()
		}
	}()

	time.Sleep(10 * time.Second)
}