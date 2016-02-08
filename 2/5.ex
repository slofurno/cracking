defmodule M do

  def backwards([x|xs]) do
    x + 10 * backwards(xs) 
  end

  def backwards([]) do
    0
  end
end

[7,1,5,3]
|> M.backwards
|> IO.inspect

[7,1,5,3]
|> Enum.reduce(0, fn(c,a) -> 10*a + c end)
|> IO.inspect
