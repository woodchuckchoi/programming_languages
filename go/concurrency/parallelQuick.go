package main

import "fmt"

func Swap(a *int, b *int) {
	*a, *b = *b, *a
}

func Partition(arr []int, low, high int) int {
	pivot := arr[high]
	idx := low

	for i := low; i < high; i++ {
		if arr[i] < pivot {
			Swap(&arr[i], &arr[idx])
			idx++
		}
	}
	Swap(&arr[high], &arr[idx])
	return idx
}

func QuickSort(arr []int, low, high int, done chan struct{}) {
	defer close(done)
	for low < high {
		pivot := Partition(arr, low, high)
		left, right := make(chan struct{}), make(chan struct{})
		go QuickSort(arr, low, pivot-1, left)
		go QUickSort(arr, pivot+1, high, right)
		i
	}
	done <- struct{}{}
}

func main() {
	fmt.Println("vim-go")
}
