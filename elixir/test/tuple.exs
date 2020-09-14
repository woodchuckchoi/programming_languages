tup = {:ok, "hello"}
IO.puts tuple_size(tup)
IO.puts elem(tup, 0)

tup = put_elem(tup, 0, :vegetable)
IO.puts elem(tup, 0)
