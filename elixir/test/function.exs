add = fn a, b -> a + b end
IO.puts add.(1,2)	# for anonymous functions . is required to show it's not a built-in named function
IO.puts is_function(add)
IO.puts is_function(add, 2)
IO.puts is_function(add, 1)

double = fn a -> add.(a, a) end
IO.puts double.(2)

x = 42
something = fn -> x = 0 end
IO.puts something.()
x = x + 1
IO.puts round(x)

list = [1, 2, true]
# IO.puts list
IO.puts length list

[1,2,3] ++ [4,5,6]

[1, true, false, 2] -- [true, 2]
