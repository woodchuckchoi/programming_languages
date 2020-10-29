package main

import (
	"fmt"
)

func main() {
	test := map[rune]int{}
	test['가'] = 3
	test['나'] = 6
	test['다'] = 9
	test['q'] = 12

	for key, val := range test {
		fmt.Printf("map[%v] = %q\n", string(key), val)
	}

	tmp := "\xbd\xb2\x3d\xbc\x20\xe2\x8c\x98"

	fmt.Println("---")

	for idx, r := range tmp {
		fmt.Printf("%#U starts at byte position %d\n", r, idx)
	}

	fmt.Println("---")

	for i := 0; i < len(tmp); i++ {
		fmt.Printf("%x ", tmp[i])
	}
	fmt.Println()
	fmt.Printf("% x", tmp)
	fmt.Println()
	fmt.Printf("%q\n", tmp)

	tmp2 := "\xe2\x8c\x98"
	fmt.Println(tmp2)

	another := []rune(tmp)
	for i := 0; i < len(another); i++ {
		fmt.Println(string(another[i]))
	}
}
