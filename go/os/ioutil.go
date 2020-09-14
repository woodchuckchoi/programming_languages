package main

import (
	"io/ioutil"
	"fmt"
	"os"
)

func main() {
	s := "Hello, World!"
	
	err := ioutil.WriteFile("hello.txt", []byte(s), os.FileMode(0644))

	if err != nil {
		fmt.Println(err)
		return
	}

	data, err := ioutil.ReadFile("hello.txt")
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Println(string(data))

}