package main

import (
	"fmt"
)

func permute(nums []int) [][]int {
	ret := [][]int {{}}

	for _, num := range nums {
		nextRet := ret
		for i:=0; i<len(ret); i++ {
			tmp := ret[i]
			tmp = append(tmp, num)
			nextRet = append(nextRet, tmp)
		}
		ret = nextRet
	}

	return ret[1:] // get rid of the empty slice
}

func main() {
	fmt.Println(permute([]int{1,2,3,4}))
}

