package auto

type AutoCompleter struct {
	Roots []*Node
	Words []string // Node.Includes will contain the indexes of the words in this slice
}

func InitialiseAutoCompleter() *AutoCompleter {
	auto := &AutoCompleter{
		Roots: []*Node{},
		Words: []string{},
	}

	return auto
}

func (a *AutoCompleter) Refresh() *AutoCompleter {
	copied := InitialiseAutoCompleter()
	for idx, word := range a.Words {
		copied.AddWord(word, idx)
	}
	return copied
}

func (a *AutoCompleter) AddWord(s string, index int) {
	cps := StringToCodePoints(s)

	root := FindRoot(a, cps[0])
	if root == nil {
		root = MakeRoot(a, cps[0])
	}
	root.Includes.Add(index)

	for _, cp := range cps[1:] {
		child := FollowNode(root, cp)
		if child == nil {
			child = SpawnNode(root, cp)
		}
		root = child
		root.Includes.Add(index)
	}
}

func (a *AutoCompleter) RetreiveWords(s string) []string {
	cps := StringToCodePoints(s)
	root := FindRoot(a, cps[0])
	if root == nil {
		return []string{}
	}
	cps = cps[1:]

	for len(cps) > 0 {
		root = FollowNode(root, cps[0])
		if root == nil {
			return []string{}
		}
		cps = cps[1:]
	}

	ret := []string{}
	for _, index := range root.Includes.Get() {
		ret = append(ret, RetreiveWordByIndex(a, index))
	}

	return ret
}

func RetreiveWordByIndex(a *AutoCompleter, index int) string {
	return a.Words[index]
}

func FindRoot(a *AutoCompleter, r rune) *Node {
	for _, node := range a.Roots {
		if node.CodePoint == r {
			return node
		}
	}
	return nil
}

func MakeRoot(a *AutoCompleter, r rune) *Node {
	newRoot := &Node{
		CodePoint: r,
		Includes:  MakeSet(),
		Nexts:     []*Node{},
	}
	a.Roots = append(a.Roots, newRoot)
	return newRoot
}
