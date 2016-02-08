defmodule Bin do
  defstruct left: nil, right: nil, value: nil

  def ff(x, n) when x == nil do
    %Bin{value: n}
  end

  def ff(%Bin{left: left, right: right, value: value}, n) do 
    cond do
      value == nil -> 
        %Bin{value: n}

      n < value ->
        new = ff(left, n)
        %Bin{left: new, right: right, value: value}

      n >= value ->
        new = ff(right, n)
        %Bin{left: left, right: new, value: value}
    end    
  end

  def test_depth(n) do
    test_depth(n, 1)
  end

  def test_depth(n, d) when n == nil do
    d
  end

  def test_depth(n, d) do
    l = test_depth(n.left, d+1)
    r = test_depth(n.right, d+1)
    if l > r do
      l
    else
      r
    end
  end

  def create_min(n, start, stop) when stop >= start do
    p = round((stop + start)/2)
    left = create_min(n, start, p - 1)
    right = create_min(n, p + 1, stop)
    %Bin{left: left, right: right, value: Enum.at(n,p)}
  end

  def create_min(n, start, stop) do
    nil
  end

  def create_min(n) do
    create_min(n, 0, Enum.count(n) - 1)
  end

  def test() do
    IO.puts "test"
  end
end

defmodule Run do

  [10,13,1,2,4,5,7,8,9,20,21]
  |> Enum.reduce(%Bin{}, fn(c,a) -> Bin.ff(a, c) end)
  |> Bin.test_depth
  |> IO.inspect


  [10,13,1,2,4,5,7,8,9,20,21]
  |> Enum.sort
  |> Bin.create_min
  |> Bin.test_depth
  |> IO.inspect
end


