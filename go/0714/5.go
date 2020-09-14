package main

import "fmt"

func sing(n int) {
	fmt.Printf("First line costs %3v, second will cost %3v\n", n*10, n*20)
}

func main() {
	for i:=1;i<11;i++ {
		sing(i)
	}
}
