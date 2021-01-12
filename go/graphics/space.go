package graphics

/*
   Z
   |
   |____Y
  /
 /
X
*/

type Point struct {
	X int
	Y int
	Z int
}

func InitPoint(x, y, z int) Point {
	return Point{
		X: x,
		Y: y,
		Z: z,
	}
}

type Object struct {
	Points []Point
	Edges  [][]bool
}

func InitObject(x, y, z int) *Object {
	p := InitPoint(x, y, z)
	obj := Object{
		Points: []Point{p},
		Edges:  [][]bool{{}},
	}

	return &obj
}

func PointIn(obj *Object, pt *Point) int {
	for idx, objPt := range obj.Points {
		if objPt == *pt {
			return idx
		}
	}
	return -1
}

func (o *Object) AddPoints(pts ...Point) {
	for _, pt := range pts {
		if PointIn(o, &pt) > -1 {
			continue
		} else {
			o.Points = append(o.Points, pt)
		}
	}
}

func (o *Object) GenerateEdges(orig, dest *Point) {
	if idx_o, idx_d := PointIn(o, orig), PointIn(o, dest); idx_o+idx_d != -2 {
		max := max(idx_o, idx_d)
		for i := 0; i < max; i++ {
			if i >= len(o.Edges) {
				o.Edges = append(o.Edges, make([]bool, max))
			} else {
				for j := len(o.Edges[i]); j < max; j++ {
					o.Edges[i] = append(o.Edges[i], false)
				}
			}
		}
		o.Edges[idx_o][idx_d] = true
		o.Edges[idx_d][idx_o] = true
	}
}

func Visualise(o *Object) {
	clearScreen()
	width, height := getTerminalSize()

	graphics := filler(width, height)

	graphicsWithAxes := addAxes(graphics)
	graphicsWithPoints := addPoints(graphicsWithAxes, o)
	printByteSlice(graphicsWithPoints)
}

type Vector struct {
	X float64
	Y float64
	Z float64
}
