package main

import (
	"fmt"
	"crypto/sha512"
)

func main() {
	s := "Hello, World!"
	h1 := sha512.Sum512([]byte(s))
	fmt.Printf("%x\n", h1)

	sha := sha512.New()
	sha.Write([]byte("Hello, "))
	sha.Write([]byte("World!"))
	h2 := sha.Sum(nil)
	fmt.Printf("%x\n", h2)
}