package main

import (
	"fmt"
	"strconv"
)

func main() {
	var (
		i	int
		k	int64
		f	float64
		s	string
		err	error
		num	int
	)
	
	i, err = strconv.Atoi("350")
	fmt.Println(i, err)
	k, err = strconv.ParseInt("cc7fdd", 16, 32)
	fmt.Println(k, err)
	k, err = strconv.ParseInt("0xcc7fdd", 0, 32)
	fmt.Println(k, err)
	f, err = strconv.ParseFloat("3.14", 64)
	fmt.Println(f, err)
	s = strconv.Itoa(340)
	fmt.Println(s)
	s = strconv.FormatInt(13402077, 16)
	fmt.Println(s)

	fmt.Sscanf("57", "%d", &num)
	fmt.Println(num)
	s = fmt.Sprint(3.14)
	fmt.Println(s)
	s = fmt.Sprintf("%x", 13402077)
	fmt.Println(s)
}
