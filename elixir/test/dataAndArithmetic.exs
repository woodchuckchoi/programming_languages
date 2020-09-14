IO.puts 1		# int
IO.puts 2.2e4	# float
IO.puts true	# bool
IO.puts :atom	# atom/symbol
IO.puts "elixir"# string


IO.puts [1,2,3] # list, doesn't print anything
'''
IO.puts {1,2,3} # tuple, cannot be printed
'''


IO.puts 5/5		# / always returns float in Elixir
IO.puts div(5,5)# div returns int
IO.puts rem(5,5)# rem is the equivalent of %
IO.puts 0b11	# binary
IO.puts 0o11	# oct
IO.puts 0x11	# hex
IO.puts round(4.8)	# round
IO.puts trunc(4.8)	# trunc

IO.puts is_boolean(true)
IO.puts is_boolean(:true)
IO.puts is_boolean(1)

IO.puts :apple
IO.puts :orange
IO.puts :apple == :orange
IO.puts :apple == :pineapple
IO.puts is_atom(false)
IO.puts is_atom(:false)
IO.puts is_atom(nil)
IO.puts is_atom(:nil)
IO.puts :"even something like this can be an atom variable:)"
string = :world
string2= "woohyuck"
IO.puts "hello #{string}"
IO.puts "hello #{string2}"
IO.puts "hello
world"

# string is binary
IO.puts is_binary("hellö")
IO.puts byte_size("hellö")	# not the surface value but the original byte code length
IO.puts String.length("hellö")	# length of the string
IO.puts String.upcase("hello")	# string module has a lot of method for string
