defmodule M do
    def main do
        stuff()
    end

    def stuff do
        IO.puts "4 == 4.0 : #{4 == 4.0}"
        IO.puts "4 === 4.0 : #{4 === 4.0}"

        IO.puts "4 != 4.0 : #{4 != 4.0}"
        IO.puts "4 !== 4.0 : #{4 !== 4.0}"

        IO.puts "5 > 4 : #{5 > 4}"
        IO.puts "5 >= 4 : #{5 >= 4}"
        IO.puts "5 < 4 : #{5 < 4}"
        IO.puts "5 <= 4 : #{5 <= 4}"

        age = 30

        IO.puts "Vote and Drive : #{age >= 31 and age >= 18}"
        IO.puts "Vote and Drive : #{age >= 31 or age >= 18}"

        IO.puts not true
    end

end