defmodule DocumentationTest do
	@moduledoc """
	How will it be shown?
	"""

	@doc "This is the only function #{__MODULE__} module has"
	def hello(), do: IO.puts "HELLO FROM #{__MODULE__}"
end
