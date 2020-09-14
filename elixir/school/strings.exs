string = <<104,101,108,108,111>>
IO.puts string

IO.puts(string <> <<0>>)

# charlist shows the codepoints in UNICODE
IO.inspect 'hełło'
# string shows the codepoints in UTF8
IO.inspect("hełło"<><<0>>)

string = "\u0061\u0301"

String.codepoints string

String.graphemes string

String.length "Hello"

String.replace("Hello", "e", "a")

String.duplicate("Oh my ", 3)

String.split("Hello World", " ")


