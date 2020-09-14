defmodule M do
  def main do
    data_stuff()
  end

  def data_stuff do
    my_str = "My Sentence"
    IO.puts "Length #{String.length(my_str)}"

    another_str = my_str <> " " <> "is long"
    IO.puts "Equal : #{"Egg"==="egg"}"

    IO.puts "My ? #{String.contains?(my_str, "My")}"

    IO.puts "First : #{String.first(my_str)}"

    IO.puts "Index 4 : #{String.at(my_str, 4)}"

    IO.puts "Substring : #{String.slice(my_str, 3, String.length(my_str))}"

    IO.inspect String.split(another_str, " ")

    IO.puts String.reverse(another_str)
    IO.puts String.upcase(another_str)
    IO.puts String.downcase(another_str)
    IO.puts String.capitalize(another_str)

    4 * 10 |> IO.puts
  end
end
