defmodule M do
    def main do
        stuff()
    end

    def stuff do
        IO.puts "5 + 3 = #{5+3}"
        IO.puts "5 - 3 = #{5-3}"
        IO.puts "5 * 3 = #{5*3}"
        IO.puts "5 / 3 = #{5/3}"
        IO.puts "5 div 3 = #{div(5, 3)}"
        IO.puts "5 rem 3 = #{rem(5, 3)}"

    end
end