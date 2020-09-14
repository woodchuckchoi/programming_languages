defmodule M do
    def main do
        stuff()
    end

    def stuff do
        capitals = %{"Alabama" => "Montgomery",
        "Alaska" => "Juneau",
        "Arizona" => "Phoenix"}

        IO.puts "Capital of Alaska is #{capitals["Alaska"]}"

        capitals2 = %{alabama: "Montgomery",
        alaska: "Juneau",
        arizona: "Phoenix"}
        
        IO.puts "Capital of Arizona is #{capitals2.arizona}"

        capitals3 = Dict.put_new(capitals, "Arkansas", "Little Rock")
    end
end