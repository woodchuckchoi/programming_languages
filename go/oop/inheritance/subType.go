package main

import "fmt"

func ExampleTotalArea() {
	fmt.Println(TotalArea([]Shape{
		Square{3},
		Rectangle{4, 5},
		Triangle{6, 7},
		RectangleCircum{Rectangle{8, 9}},
		WrongRectangle{Rectangle{1, 2}},
	}))
}
