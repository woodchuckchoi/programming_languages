package graphics

type Point struct {
	X float64
	Y float64
	Z float64
}

func InitPoint(x, y, z float64) Point {
	return Point{
		X: x,
		Y: y,
		Z: z,
	}
}

type Object struct {
	Points []Point
	Edges  map[*Point][]*Point
}

func InitObject(x, y, z float64) *Object {
	p := InitPoint(x, y, z)
	obj := Object{
		Points: []Point{p},
		Edges:  map[*Point][]*Point{},
	}

	return &obj
}

func (o *Object) AddPoints(pts ...Point) {
	o.Points = append(o.Points, pts...)
}

func (o *Object) GenerateEdges() {

}

type Vector struct {
	X float64
	Y float64
	Z float64
}
