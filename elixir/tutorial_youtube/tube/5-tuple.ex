defmodule M do
    def main do
        stuff
    end
    
    def stuff do
        my_stats = {175, 6.25, :Hyuck}

        IO.puts "Tuple #{is_tuple(my_stats)}"
        IO.inspect my_stats

        my_stats2 = Tuple.append(my_stats, 42)

        IO.puts "Age #{elem(my_stats2, 3)}"

        IO.puts "Size: #{tuple_size(my_stats2)}"

        my_stats3 = Tuple.delete_at(my_stats2, 0)

        my_stats4 = Tuple.insert_at(my_stats3, 0, 1974)

        many_zeros = Tuple.duplicate(0, 5)

        IO.inspect my_stats2 
        IO.inspect my_stats3
        IO.inspect many_zeros

        {weight, height, name} = {175, 6.25, "Hyuck"}
        
        IO.puts "#{name} #{height} #{weight}"

    end
end