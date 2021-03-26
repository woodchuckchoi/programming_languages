package main

import (
  "fmt"
)

func permute(curSlice []int, curIdx int, record *[][]int) {
  if curIdx == len(curSlice) -1 {
    *record = append(*record, copySlice(curSlice))
  }

  for i:=curIdx; i<len(curSlice); i++ {
    swapSlice(curSlice, curIdx, i)

    permute(curSlice, curIdx+1, record)

    swapSlice(curSlice, curIdx, i)
  }
}

func swapSlice(slice []int, a, b int) {
  tmp := slice[a]
  slice[a] = slice[b]
  slice[b] = tmp
}

func copySlice(origin []int) []int {
  ret := make([]int, len(origin))
  for idx, val := range origin {
    ret[idx] = val
  }
  return ret
}

func main() {
  record := &[][]int {}
  permute([]int {1,2,3}, 0, record)
  fmt.Println(*record)
}
