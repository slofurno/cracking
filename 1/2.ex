defmodule M do
  def zipcompare([x|xs], [y|ys]) do
    case x==y do
      true ->
        zipcompare(xs, ys)
      false ->
        false
    end
  end

  def zipcompare([], []) do
    true
  end

end

first = to_char_list("race car") |> Enum.sort
second = to_char_list("car race") |> Enum.sort

M.zipcompare(first, second)
|> IO.inspect

