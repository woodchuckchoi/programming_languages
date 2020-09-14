# With the use macro we can enable another module to modify our current module’s definition. When we call use in our code we’re actually invoking the __using__/1 callback defined by the provided module. The result of the __using__/1 macro becomes part of our module’s definition. To get a better understanding how this works let’s look at a simple example:

defmodule Hello do
	defmacro __using__(opts) do
		greeting = Keyword.get(opts, :greeting, "Hi")
		
		# Unquote is there because it references a variable that's outside the quote block
		quote do
			def hello(name), do: unquote(greeting) <> ", #{name}"
		end
	end
end
