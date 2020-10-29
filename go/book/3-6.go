package main

import "fmt"

func main() {
	ExampleArray()
	TestSort()
	TestStringSearch()
	QueueTest()
	TestMultiSet()
}

func ExampleArray() {
	fruits := [...]string{"사과", "바나나", "토마토", "수박"}
	for _, fruit := range fruits {
		runeFruit := []rune(fruit)
		var post string = "은"
		if (runeFruit[len(runeFruit)-1]-'가')%28 == 0 {
			post = "는"
		}
		fmt.Printf("%v%v 맛있다.\n", fruit, post)
	}
}

func TestSort() {
	s := []int{321, 534, 132, 645, 7456, 523, 35, 745, 523}
	HeapSort(s)
}

func HeapSort(s []int) {
	for i := len(s) / 2; i > -1; i-- {
		Heapify(s, i)
	}

	for len(s) > 0 {
		s[0], s[len(s)-1] = s[len(s)-1], s[0]
		fmt.Println(s[len(s)-1])
		s = s[:len(s)-1]
		Heapify(s, 0)
	}
}

func Heapify(s []int, i int) {
	var (
		min   = i
		left  = 2*i + 1
		right = 2*i + 2
	)

	if left < len(s) {
		if s[left] < s[min] {
			min = left
		}
	}

	if right < len(s) {
		if s[right] < s[min] {
			min = right
		}
	}

	if min != i {
		s[i], s[min] = s[min], s[i]
		Heapify(s, min)
	}
}

func TestStringSearch() {
	s := "abdgiloqy"
	t := "d"

	fmt.Println(Search(s, t))
}

func Search(s string, t string) (idx int) {
	var (
		start = 0
		end   = len(s) - 1
	)
	idx = -1

	for start <= end {
		mid := (start + end) / 2
		fmt.Println(start, mid, end)
		if string(s[mid]) == t {
			idx = mid
			break
		} else if string(s[mid]) > t {
			end = mid - 1
		} else {
			start = mid + 1
		}
	}
	return
}

func QueueTest() {
	q := &Queue{1, 2, 3}
	q.Append(4, 5)
	fmt.Println((*q)[3])
	fmt.Println(q.Pop())
	fmt.Println(q.Pop())
}

type Queue []int

func (q *Queue) Append(nums ...int) {
	*q = Queue(append([]int(*q), nums...))
}

func (q *Queue) Pop() int {
	if len([]int(*q)) <= 0 {
		return -1
	}
	tmp := []int(*q)[0]
	*q = Queue([]int(*q)[1:])
	return tmp
}

func TestMultiSet() {
	m := NewMultiSet()
	fmt.Println(String(m))
	fmt.Println(Count(m, "3"))
	Insert(m, "3")
	Insert(m, "3")
	Insert(m, "3")
	Insert(m, "3")
	fmt.Println(String(m))
	fmt.Println(Count(m, "3"))
	Insert(m, "1")
	Insert(m, "2")
	Insert(m, "5")
	Insert(m, "7")
	Erase(m, "3")
	Erase(m, "5")
	fmt.Println(Count(m, "3"))
	fmt.Println(Count(m, "1"))
	fmt.Println(Count(m, "2"))
	fmt.Println(Count(m, "5"))
}

func NewMultiSet() map[string]int {
	return map[string]int{}
}

func Insert(m map[string]int, val string) {
	m[val]++
}

func Erase(m map[string]int, val string) {
	if _, ok := m[val]; ok {
		m[val]--
	}
}

func Count(m map[string]int, val string) int {
	return m[val]
}

func String(m map[string]int) string {
	ret := "{ "
	for key, val := range m {
		for i := 0; i < val; i++ {
			ret += fmt.Sprintf("%v ", key)
		}
	}
	ret += "}"

	return ret
}
