package main

import (
	"fmt"
	"sync/atomic"
	"time"
)

func main() {
	cnt := int64(10)
	for i := 0; i < 10; i++ {
		go func() {
			atomic.AddInt64(&cnt, -1)
		}()
	}
	for atomic.LoadInt64(&cnt) > 0 {
		time.Sleep(100 * time.Millisecond)
	}
	fmt.Println(cnt)
}
