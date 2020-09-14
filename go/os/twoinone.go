package main

import (
	"fmt"
	"os"
	"bufio"
)

func main() {
	file, err := os.OpenFile(
		"hello.txt",
		os.O_CREATE|os.O_RDWR|os.O_TRUNC,
		os.FileMode(0644),
	)
	if err != nil {
		fmt.Println(err)
		return
	}
	defer file.Close()

	w := bufio.NewWriter(file)
	r := bufio.NewReader(file)

	rw := bufio.NewReadWriter(r, w)

	rw.WriteString("Hello, fuckable World!")
	rw.Flush()

	file.Seek(0, os.SEEK_SET)
	
	data := make([]string, 10)

	for {
		line, _, err := rw.ReadLine()
		if err != nil {
			fmt.Println(err)
			break
		}
		data = append(data, string(line))
	}
	fmt.Println("Here is the data")
	fmt.Println(data)
}