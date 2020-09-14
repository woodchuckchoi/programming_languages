defmodule M do
    def main do
        stuff()
    end

    def stuff do
        IO.puts "Sum : #{sum([1,2,3])}"

        loop(5, 1)
    end

    def sum([head|tail]) do
        sum = head + sum(tail)
        sum
    end
    def sum([]), do: 0

    # def loop(0, _), do: nil
    def loop(max, min) do
        if max < min do
            nil
        else
            IO.puts "Num: #{max}"
            loop(max - 1, min)
        end
    end
end