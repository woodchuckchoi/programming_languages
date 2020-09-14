defmodule Sayings.Greetings do
	def basic(name), do: "Hi, #{name}"
end

defmodule Example do
	alias Sayings.Greetings

	def greeting(name), do: Greetings.basic(name)
end

# Without alias

defmodule Example do
	def greeting(name), do: Sayings.Greetings.basic(name)
end

# Aliasing with as

defmodule Example do
	alias Sayings.Greetings, as: Hi

	def print_message(name), do: Hi.basic(name)
end

# Multiple alias

defmodule Example do
	alias Sayings.{Greetings, Farewells}
end
