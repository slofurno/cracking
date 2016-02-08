defmodule M do

  def check_two(l, [x|xs]) do
    case (x == l) do
      true -> 
        false
      false -> 
        check_two(x, xs)
    end
  end

  def check_two(_, []) do
    true
  end

  def check_two([x|xs]) do
    check_two(x, xs)
  end

  def check_two([]) do
    true
  end

end

wtf = fn -> IO.puts "HEY" end

"words with duplicate chars"
|> to_char_list
|> Enum.sort
|> M.check_two
|> IO.inspect

wtf.()
