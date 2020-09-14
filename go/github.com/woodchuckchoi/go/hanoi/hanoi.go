package main

import (
	"fmt"
)

func Hanoi(num, from, dest, aux int) {
	if num == 1 {
		fmt.Println(from, "->", dest)
	} else {
		Hanoi(num-1, from, aux, dest)
		Hanoi(1, from, dest, aux)
		Hanoi(num-1, aux, dest, from)
	}
}

func main() {
	var num int
	fmt.Scanf("%d", &num)
	Hanoi(num, 1, 3, 2)
}
