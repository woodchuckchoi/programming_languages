package main

import (
	"fmt"
	"os"
)

func main() {
	f, err := os.Open("test.txt")
	if err != nil {
		fmt.Println("Error!")
		return 
	}
	defer f.Close()

	var num int

	if _, err := fmt.Fscanf(f, "%d\n", &num); err == nil {
		fmt.Println(num)
	}
}
