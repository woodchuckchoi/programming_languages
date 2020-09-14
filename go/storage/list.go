package main

import (
	"fmt"
	"container/list"
)

func main() {
	l := list.New()
	l.PushBack(10)
	l.PushBack(20)
	l.PushBack(30)

	fmt.Println("front", l.Front().Value)
	fmt.Println("back", l.Back().Value)

	for e := l.Front();e != nil;e = e.Next() {
		fmt.Println(e.Value)
	}

	l.PushBack("hello")
	fmt.Println(l.Back().Value, l.Back().Prev().Value)
}