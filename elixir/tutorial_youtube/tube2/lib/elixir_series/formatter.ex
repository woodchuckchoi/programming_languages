defmodule ElixirSeries.Formatter do
	@callback format_name(ElixirSeries.Person.t()) :: String.t()
end
