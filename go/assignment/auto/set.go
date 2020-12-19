package auto

type Set map[int]struct{}

func (s *Set) Add(i int) {
	if _, ok := (*s)[i]; !ok {
		(*s)[i] = struct{}{}
	}
}

func (s *Set) Get() []int {
	ret := []int{}
	for key := range *s {
		ret = append(ret, key)
	}
	return ret
}

func (s *Set) Remove(i int) {
	delete(*s, i)
}

func MakeSet() Set {
	return Set{}
}
