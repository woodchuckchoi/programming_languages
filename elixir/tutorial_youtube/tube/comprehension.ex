defmodule M do
    def main do
        stuff()
    end

    def stuff do
        
        dbl_list = for n <- [1,2,3], do: n*2
        IO.inspect dbl_list

        even_list = for n <- [1,2,3,4], rem(n, 2) === 0, do: n
        IO.inspect even_list

        err = try do
            5 / 0

            rescue
                ArithmeticError -> "Can't Divide By Zero"
        end

        IO.puts err

    end
end