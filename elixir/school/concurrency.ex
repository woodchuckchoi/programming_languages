defmodule Example do
	def explode, do: exit(:kaboom)

	def double(x) do
		:timer.sleep(2000) # Task for expensive task, that you can retreive the return value of later
		x * 2
	end

	def run do
		spawn_monitor(Example, :explode, []) # monitor for receiving state from spawned process
		
		receive do
			{:DOWN, _ref, :process, _from_pid, reason} -> IO.puts "Exit reason: #{reason}"
		end
	end

#	def run do
#		Process.flag(:trap_exit, true)
#		spawn_link(Example, :explode, []) # link for receiving state from spawned process, with Process.flag settings
#
#		receive do
#			{:EXIT, _from_pid, reason} -> IO.puts "Exit reason: #{reason}"
#		end
#	end

	def listen do
		receive do
			{:ok, data} -> IO.puts data
		end
		listen()
	end

	def add(a, b) do 
		IO.puts a+b 
	end
end
