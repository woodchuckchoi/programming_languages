package main

import (
	"container/heap"
	"fmt"
)

type MinHeap []int

func (h MinHeap) Len() int {
	return len(h)
}

func (h MinHeap) Less(i, j int) bool {
	r := h[i] < h[j]
	fmt.Printf("Less %d < %d %t\n", h[i], h[j], r)
	return r
}

func (h MinHeap) Swap(i, j int) {
	fmt.Printf("Swap %d %d\n", h[i], h[j])
	h[i], h[j] = h[j], h[i]
}

func (h *MinHeap) Push(x interface{}) {
	fmt.Println("Push", x)
	*h = append(*h, x.(int))
}

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = (*h)[:n-1]
	return x
}

func main() {
	data := new(MinHeap)

	heap.Init(data)
	heap.Push(data, 5)
	heap.Push(data, 2)
	heap.Push(data, 3)
	heap.Push(data, 7)

	fmt.Println(data, "Min Value: ", (*data)[0])
}