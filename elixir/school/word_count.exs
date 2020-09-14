filename = IO.gets("File to count the words from: ") |> String.trim

body = File.read!(filename) |> String.trim

IO.inspect body

words = String.split(body, ~r{[^\w]+}) 
	|> Enum.filter(fn n -> String.length(n) > 0 end)
	|> Enum.count

IO.inspect words
