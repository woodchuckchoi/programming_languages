package main

import "fmt"

func BabyNames(first, second string) <-chan string {
	c := make(chan string)
	go func() {
		defer close(c)
		for _, f := range first {
			for _, s := range second {
				c <- string(f) + string(s)
			}
		}
	}()
	return c
}

func ExampleBabyNames() {
	for n := range BabyNames("성정명재경", "준호우훈진") {
		fmt.Print(n, ", ")
	}
}

func main() {
	ExampleBabyNames()
}
