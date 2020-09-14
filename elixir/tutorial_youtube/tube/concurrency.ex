defmodule M do
    def main do
        stuff()
    end

    def stuff do
        
        spawn(fn -> loop(50, 1) end)
        spawn(fn -> loop(100, 50) end)

        send(self(), {:french, "Bob"})

        receive do
            {:german, name} -> IO.puts "Guten tag #{name}"
            {:french, name} -> IO.puts "Bonjour #{name}"
            {:english, name} -> IO.puts "Hello #{name}"
        after
            500 -> IO.puts "Time Up"
        end
        

    end

    def loop(max, min) do
        if max > min do 
            IO.puts max
            loop(max-1, min)
        end
    end
end