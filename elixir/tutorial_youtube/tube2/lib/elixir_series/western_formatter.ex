defmodule ElixirSeries.WesternFormatter do
	@behaviour ElixirSeries.Formatter

	@impl true
	def format_name(%{first_name: first_name, last_name: last_name}) do
		"#{first_name} #{last_name}"
	end 

end
