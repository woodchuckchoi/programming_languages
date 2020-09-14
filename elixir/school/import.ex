defmodule Example do
	# Import literally imports the functions inside the module that comes after it
	import List, only: [last: 1]
	# import List, except: [last: 1]
	# import List, only: :functions
	# import List, only: :macros
	[1,2,3]
	|> last
	|> IO.puts
end
