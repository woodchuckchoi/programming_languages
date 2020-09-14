defmodule ElixirSeries.AsianFormatter do
	@behaviour ElixirSeries.Formatter

	@impl true
	def format_name(%{first_name: first_name, last_name: last_name}) do
		"#{last_name} #{first_name}"
	end 

end