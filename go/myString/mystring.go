// Package mystring has several string utils such as Reverse, toLower, toUpper...
package mystring

import (
	"fmt"
)

// Reverse reverses a sequence of string
func Reverse(s string) string {
	reverse := []rune(s)
	
	for index := 0; index < int((len(s)+1)/2); index++ {
		reverse[index], reverse[len(s)-1-index] = reverse[len(s)-1-index], reverse[index]
	}

	return string(reverse)
}

func main() {
	fmt.Println(Reverse("Hello, World!"))
	fmt.Println(Reverse("The quick brown fox jumps over the lazy dog."))
}