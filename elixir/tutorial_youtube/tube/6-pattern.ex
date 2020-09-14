defmodule M do
    def main do
        stuff()
    end

    def stuff do
        [length, width] = [20, 30]
        IO.puts "Width : #{width}"

        [_, [_, a]] = [20, [30, 40]]
        IO.puts "Get num : #{a}"
    end

    def display_list([word|words]) do
        IO.puts word
        display_list(words)
    end

    def display_list([]), do: nil
end