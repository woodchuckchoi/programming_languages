package main

import (
	"fmt"
)

type Test struct {
	name	string
	age		int
}

func younger(t Test) {
	t.age = t.age-1
}

func take5(s []int) {
	s[5] = 42
	s = append(s, 42)
}

func give5(m map[int]int) {
	m[5] = 5
}

func take5Array(a [10]int) {
	a[5] = 42
}

func main() {
	t := Test{name: "Someone", age: 29}
	younger(t)
	fmt.Println(t) // Test{name: "Someone", age: 29}

	// Struct

	s := make([]int, 10)
	take5(s)
	fmt.Println(s) // 0,0,0,0,0,42,0,0,0,0

	// Slice - header and body(array), the body can change but not the header

	m := map[int] int {}
	give5(m)
	fmt.Println(m) // map{5:5}

	// Map

	a := [10]int {}
	take5Array(a)
	fmt.Println(a) // 0,0,0,0,0,0,0,0,0,0

	// Array
}
