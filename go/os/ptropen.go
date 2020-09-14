package main

import (
	"fmt"
	"os"
)

func main() {
	file, err := os.OpenFile(
		"hello.txt",
		os.O_RDWR|os.O_CREATE|os.O_TRUNC,
		os.FileMode(0644),
	)

	if err != nil {
		fmt.Println(err)
		return
	}
	defer file.Close()

	n := 0
	s := "Hiya"
	n, err = file.Write([]byte(s))
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Println(n, "bytes saved")

	fi, err := file.Stat()
	if err != nil {
		fmt.Println(err)
		return
	}

	data := make([]byte, fi.Size())

	file.Seek(0, os.SEEK_SET)

	n, err = file.Read(data)
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Println(n, "bytes read")
	fmt.Println(string(data))
}
