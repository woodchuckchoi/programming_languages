defmodule Example do
	def timed(fun, args) do
		{time, result} = :timer.tc(fun, args)
		IO.puts "Time: #{time} "
		IO.puts "Result: #{result}"
	end
end


