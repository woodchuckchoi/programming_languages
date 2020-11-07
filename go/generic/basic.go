package main

import "fmt"

func String(m Something) string {
	to_int, ok := m.(int)
	fmt.Println(to_int, ok)
	if ok {
		return fmt.Sprintf("%v", to_int)
	} else {
		return fmt.Sprintf("nothing")
	}
}

type Something interface{}

func main() {
	var x interface{} = 42
	fmt.Println(String(x))
}
