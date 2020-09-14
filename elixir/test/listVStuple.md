List vs Tuple in Elixir

List = Linked List (Accessing an element is a linear procedure)

list = [1,2,3]
[0] ++ list
is faster than
list ++ [4]

Tuple is stored contiguously in memory. Accessing or getting the size of tupple is fast. But updating, re-declaring a tuple is expensive.

tuple = {:a, :b, :c, :d}
put_elem(tuple, 2, :e)

When updated, lists and tuples share the elements. Still immutable, since any operations on tuples, lists are immutable, too.
