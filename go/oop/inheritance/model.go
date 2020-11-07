package main

type Shape interface {
	Area() float32
}

type Triangle struct {
	Width, Height float32
}

func (t Triangle) Area() float32 {
	return 0.5 * t.Width * t.Height
}

type Square struct {
	Size float32
}

func (s Square) Area() float32 {
	return s.Size * s.Size
}
func TotalArea(shapes []Shape) float32 {
	ret := float32(0)
	for _, shape := range shapes {
		ret += shape.Area()
	}
	return ret
}
