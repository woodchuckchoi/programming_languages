package main

import (
	"fmt"
	"runtime"
)

func main() {
	runtime.GOMAXPROCS(1)
	s := "Test"
	for i := 0; i < 100; i++ {
		go func() {
			fmt.Println(s, i)
		}()
	}

	fmt.Scanln()
}

// package main

// import (
// 	"fmt"
// 	"runtime"
// )

// func main() {
// 	runtime.GOMAXPROCS(runtime.NumCPU())
// 	fmt.Println(runtime.GOMAXPROCS(0))

// 	s := "Hello, World!"

// 	for i := 0; i < 100; i++ {
// 		go func(n int) {
// 			fmt.Println(s, n)
// 		}(i)
// 	}

// 	fmt.Scanln()
// }