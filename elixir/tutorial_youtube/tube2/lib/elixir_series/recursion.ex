defmodule Recursion do
	def factorial(1), do: 1 # order do matter
	def factorial(n) when n > 0, do: n*factorial(n-1) # guard needed!
end
