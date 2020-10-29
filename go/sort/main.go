package main

import (
	"fmt"
)

func main() {
	test := []int{1, 2, 3}

	Do(test)

	fmt.Println(test)

	fmt.Println(len(test), cap(test))
	test = test[1:]
	fmt.Println(len(test), cap(test))

}

func Do(s []int) {
	s[0], s[len(s)-1] = s[len(s)-1], s[0]
}
