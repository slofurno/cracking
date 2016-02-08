
escaped = "%20" |> to_char_list

"some words here"
|> to_char_list
|> Enum.reduce([], fn
     x, acc when x == 32 -> acc ++ escaped
     x, acc              -> acc ++ [x] 
  end)
|> IO.inspect

#1..3
#|> Enum.reduce(0, fn(x, acc) -> acc + x end)
#|> IO.inspect
