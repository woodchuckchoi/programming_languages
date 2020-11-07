package main

type WrongRectangle struct {
	Rectangle
}

func (r WrongRectangle) Area() float32 {
	return r.Rectangle.Area() * 2
}

/*
func main() {
	r := WrongRectangle{Rectangle{3, 4}}
	fmt.Println(r.Area())
}
*/
