package main

import "fmt"

func Move(n, src, dest, aux int) {
	if n <= 0 {
		return
	}
	Move(n-1, src, aux, dest)
	fmt.Println(src, "->", dest)
	Move(n-1, aux, dest, src)
}

func Hanoi(disc int) {
	fmt.Println("Number of disks:", disc)
	Move(disc, 1, 2, 3)
}

func main() {
	Hanoi(3)
}
