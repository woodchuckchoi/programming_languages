package main

import (
	"fmt"
	"math/rand"
	"time"
)

func hello(n int) {
	j := rand.Intn(100)
	time.Sleep(time.Duration(j))
	fmt.Println(n)
}

func main() {
	for i := 0; i < 100; i++ {
		go hello(i)
	}
	fmt.Scanln()
}