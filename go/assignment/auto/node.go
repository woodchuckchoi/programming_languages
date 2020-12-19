package auto

type Node struct {
	CodePoint rune
	Includes  Set
	Nexts     []*Node
}

func FollowNode(n *Node, r rune) *Node {
	for _, child := range n.Nexts {
		if child.CodePoint == r {
			return child
		}
	}
	return nil
}

func SpawnNode(n *Node, r rune) *Node {
	newNode := &Node{
		CodePoint: r,
		Includes:  MakeSet(),
		Nexts:     []*Node{},
	}
	n.Nexts = append(n.Nexts, newNode)
	return newNode
}
