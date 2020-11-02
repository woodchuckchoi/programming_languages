package main

import "sync"

func FanIn(ins ...<-chan int) <-chan int {
	out := make(chan int)
	var wg sync.WaitGroup
	wg.Add(len(ins))
	for _, in := range ins {
		go func(in <-chan int) {
			defer wg.Done()
			for num := range in {
				out <- num
			}
		}(in)
	}
	// returns out first, goroutine lazily adds to out
	go func() {
		wg.Wait()
		close(out)
	}()
	return out
}

func main() {
	//c := FanIn(c1, c2, c3)
}
