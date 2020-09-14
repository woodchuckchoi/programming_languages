package main

import (
	"fmt"
	"flag"
)

func main() {
	title := flag.String("title", "", "film title")
	runtime := flag.Int("runtime", 0, "runtime")
	rating := flag.Float64("rating", 0.0, "ratings")
	release := flag.Bool("release", false, "released")

	flag.Parse()

	if flag.NFlag() == 0 {
		flag.Usage()
		return
	}

	fmt.Printf(
		"영화 이름: %s\n상영 시간: %d\n평점: %.2f\n",
		*title,
		*runtime,
		*rating,
	)

	var tmp string

	if *release == true {
		tmp = "개봉"
	} else {
		tmp = "미개봉"
	}

	fmt.Println("개봉 여부:", tmp)
}