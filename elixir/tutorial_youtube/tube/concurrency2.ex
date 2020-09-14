defmodule Example do
	def main do
		spawn(Example, :add, [2, 3])
	end

	def explode, do: exit(:kaboom)

	def run do
		{pid, ref} = spawn_monitor(Example, :explode, [])

		receive do
			{:DOWN, ref, :process, from_pid, reason} -> IO.puts "Exit reason: #{reason}"
		end
	end

#	def run do
#		Process.flag(:trap_exit, true)
#		spawn_link(Example, :explode, [])
#
#		receive do
#			{:EXIT, from_pid, reason} -> IO.puts "Exit reason #{reason}"
#		end
#	end

	def listen do
		receive do
			{:ok, "hello"} -> IO.puts "World"
		end

		listen
	end

	def add(a, b) do
		IO.puts a+b
	end
end
