package main

import (
	"fmt"

	"golang.org/x/crypto/ssh/terminal"
)

func main() {
	width, height, _ := terminal.GetSize(0)

	fmt.Println(width, height)
}
