package main

import (
	"fmt"
	"log"
)

func hello(i int) (string, error) {
	if i == 1 {
		s := fmt.Sprintln("Hello", i)
		return s, nil
	}

	return "", fmt.Errorf("%d is not 1.", i)
}

func main() {
	defer func() {
		s := recover()
		fmt.Println(s)
	}()

	s, err := hello(1)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(s)

	s, err = hello(2)
	if err != nil {
		log.Panic(err)
	}

	fmt.Println(s)
}