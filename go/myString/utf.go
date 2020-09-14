package main

import (
	"fmt"
)

func Reverse(s string) string {
	reverse := []rune(s)

	for i := 0; i < int((len(s)+1)/2); i ++ {
		reverse[i], reverse[len(s)-1-i] = reverse[len(s)-1-i], reverse[i]
	}

	return string(reverse)
}

func main() {
	var s string = "This is not the end"
	var t string = "이건 끝이 아니야"

	fmt.Println(Reverse(s))
	fmt.Println(len(t))

	q := []rune(t)
	fmt.Println(len(q))
}