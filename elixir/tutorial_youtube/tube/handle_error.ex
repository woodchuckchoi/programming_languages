defmodule M do
	def main do
		stuff2()
	end
	
	def stuff do
		raise "Oh no!"
		IO.puts "It will not be printed!"
	end
	def stuff2 do
		try do
			raise "Oh no!"
		rescue
			e in RuntimeError -> IO.puts "An error occurred: #{e.message}"
		end
	end
	def stuff3 do
		try do
			raise "Oh no!"
		rescue
			e in KeyError -> IO.puts "Error occured #{e.message}"
			e in RuntimeError -> IO.puts "Error!!! #{e.message}"
		after
			IO.puts "Error handled!"
		end
	end
end
