package main

type Rectangle struct {
	Width, Height float32
}

func (r Rectangle) Area() float32 {
	return r.Width * r.Height
}

type RectangleCircum struct {
	Rectangle
}

func (r RectangleCircum) Circum() float32 {
	return 2 * (r.Width + r.Height)
}

/*
func main() {
	r := RectangleCircum{Rectangle{3, 4}}
	fmt.Println(r.Area())
	fmt.Println(r.Circum())
}
*/
