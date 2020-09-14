package main

import (
	"fmt"
	"strconv"
)

func formatString(arg interface{}) string {
	switch arg.(type) {
	case int:
		i := arg.(int)
		return strconv.Itoa(i)
	case float32:
		f := arg.(float32)
		return strconv.FormatFloat(float64(f), 'f', -1, 32)
	case float64:
		f := arg.(float64)
		return strconv.FormatFloat(f, 'f', -1, 64)
	case string:
		s := arg.(string)
		return s
	default:
		return "Error"
	}
}

func main() {
	fmt.Println(formatString(1))
	fmt.Println(formatString(2.5))
	fmt.Println(formatString("Hello, World!"))
}

// package main

// import (
// 	"fmt"
// )

// type Duck struct {
// }

// func (d Duck) quack() {
// 	fmt.Println("Quack!")
// }

// func (d Duck) feathers() {
// 	fmt.Println("This duck has black and white feathers.")
// }

// type Person struct {
// }

// func (p Person) quack() {
// 	fmt.Println("Kuack!")
// }

// func (p Person) feathers() {
// 	fmt.Println("This person is quite naked.")
// }

// type Quacker interface {
// 	quack()
// 	feathers()
// }

// func intoForest(q Quacker) {
// 	q.quack()
// 	q.feathers()
// }

// func main() {
// 	var Donald Duck
// 	var John Person
// 	intoForest(Donald)
// 	intoForest(John)

// 	if v, ok := interface{}(Donald); ok{
// 		fmt.Println(v, ok)
// 	}
// }