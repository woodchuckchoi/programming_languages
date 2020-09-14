package main

import (
	"fmt"
)

func main() {
	for i, r := range "가나다" {
		fmt.Println(i, r, string(r))
	}
	fmt.Println(len("가나다"))

	kor := []byte("가나다")
	fmt.Println(string(kor[1:3]))
}
