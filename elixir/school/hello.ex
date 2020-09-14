defmodule Hello do
	def hello(name\\"Roy") when is_binary(name) do
		phrase() <> name
	end

	def hello(name) when is_list(name) do
		name
		|> Enum.join(", ")
		|> hello
	end

	defp phrase, do: "Hello"
end
