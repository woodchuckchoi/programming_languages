package main

import (
	"github.com/woodchuckchoi/graphics"
)

func main() {
	o := graphics.InitObject(0, 0, 0)

	o.AddPoints(graphics.InitPoint(1, 3, 3))
	o.AddPoints(graphics.InitPoint(4, 3, 15))

	graphics.Visualise(o)
}
