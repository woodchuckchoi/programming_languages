package main

import (
	"fmt"
)

func Fibo(f func(int, map[int] int) int) func(int) int{
	memo := map[int] int{1:1, 2:1}

	return func(idx int) int {
		val := f(idx, memo) 
		memo[idx] = val
		return val
	}
}

func Fibo_inner(idx int, m map[int] int) int {
	if val, ok := m[idx]; ok {
		fmt.Println("Found IDX ", idx)
		return val
	}
	
	val := Fibo_inner(idx-1, m) + Fibo_inner(idx-2, m)
	return val
}


func main() {
	my_fibo := Fibo(Fibo_inner)
	for i := 1; i < 20; i++ {
		fmt.Println(my_fibo(i))
	}
}
