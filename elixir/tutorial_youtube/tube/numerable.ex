defmodule M do
    def main do
        stuff()
    end

    def stuff do
        IO.puts "Even List : #{Enum.all?([1,2,3], 
        fn(n) -> rem(n, 2) === 0 end)}"

        IO.puts "Even List : #{Enum.any?([1,2,3],
        fn(n) -> rem(n, 2) === 0 end)}"

        Enum.each([1,2,3], fn(n) -> if rem(n, 2) === 0, do: IO.puts n end)

        Enum.filter([1,2,3], fn(n) -> rem(n, 2) === 0 end) |> Enum.each(fn(n) -> IO.puts n end)

        dbl_list = Enum.map([1,2,3], fn(n) -> n*2 end)

        sum_vals = Enum.reduce([1,2,3], fn(n, sum) -> n+sum end)
        sum_vals

        IO.inspect Enum.uniq([1,2,2])
    end
end