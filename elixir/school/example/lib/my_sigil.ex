defmodule MySigil do
	@moduledoc """
	#{__MODULE__} adds an arbitrary sigil
	"""
	@doc """
	sigil_p/2 will upcase the string after the sigil
	"""
	def sigil_p(string, []), do: String.upcase(string)
end
