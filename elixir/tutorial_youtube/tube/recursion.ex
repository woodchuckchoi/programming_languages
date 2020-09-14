defmodule M do
    def main do
        stuff()
    end

    def stuff do
        IO.puts factorial(10)
    end

    def factorial(n) do
        # if n < 2 do
        #     1
        # else
        #     n*factorial(n-1)
        # end
        cond do
            n > 1 -> n * factorial(n-1)
            true -> 1
        end
    end
end