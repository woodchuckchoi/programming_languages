package main

func main() {
	select {
	case n := <-c1:
		//do something
	case n := <-c2:
		//do something
	case c3 <- f():
		//always triggers as long as c3 contains f()
	default:
		//nothings ready
	}
}
