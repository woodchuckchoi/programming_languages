package tester

import "testing"

func BenchmarkSum(b *testing.B) {
	for i := 0; i < b.N; i++ {
		Sum(1, 2)
	}
}

// func TestSum(t *testing.T) {
// 	r := Sum(1, 2)
// 	if r != 3 {
// 		t.Error("Result is not 3")
// 	}
// }