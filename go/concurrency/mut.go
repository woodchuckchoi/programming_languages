package main

import (
	"fmt"
	"sync"
)

type Accessor struct {
	R *Resource
	L *sync.Mutex
}

func main() {
	fmt.Println("vim-go")
}
