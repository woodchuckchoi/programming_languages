package main

import (
	"fmt"
	"os"
)

func main() {
	file, err := os.Open("hello.txt")
	if err != nil {
		fmt.Println(err)
		return
	}
	defer file.Close()

	fi, err := file.Stat()
	if err != nil {
		fmt.Println(err)
		return
	}

	data := make([]byte, fi.Size())

	n, err := file.Read(data)
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Println(n, "bytes read from file", fi.Name())
	fmt.Println(string(data))
}