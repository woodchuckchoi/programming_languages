defmodule M do
    def main do
       stuff 
    end

    def stuff do
        age = 13

        if age >= 18 do
            IO.puts "Can vote"
        else
            IO.puts "Can't vote"
        end

        unless age === 18 do
            IO.puts "Not 18"
        else
            IO.puts "You are 18"
        end

        cond do
            age >= 18 -> IO.puts "You can vote"
            age >= 16 -> IO.puts "You can drive"
            age >= 14 -> IO.puts "You can wait"            
            true -> IO.puts "Default"
        end

        case 2 do
            1 -> IO.puts "1"
            2 -> IO.puts "2"
            _ -> IO.puts "other"
        end

        IO.puts "Ternary : #{if age > 18, do: "Can vote", else: "Can't vote"}"
    end
end