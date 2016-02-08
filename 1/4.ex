defmodule M do 
  def twos([x|xs], last) when last == 32 do 
    twos(xs, x)
  end

  def twos([x|_xs], last) when x != last do
    false
  end

  def twos([_x|xs], _last) do
    twos(xs)
  end

  def twos([], _) do 
    true 
  end
  
  def twos([]) do 
    true
  end

  def twos([x|xs]) do
    twos(xs, x) 
  end

  def seek([x|xs], n) do
    
  end

  def start([x|xs]) do
    
  end

  def roll([x|xs], agg) do
    case x do
      32 -> agg
    end 
  end

  def is_palindrome(x) do
    !(x > 1)
  end
end

palindrome_check = fn(x) -> 
  x
  |> to_char_list
  |> Enum.filter(fn(x) -> x != 32 end)
  |> Enum.reduce(%{}, fn (c, a) ->
      if Map.has_key?(a, c) do
        Map.put(a, c, a[c]+1)
      else
        Map.put(a, c, 1) 
      end
     end)
  |> Enum.reduce(0, fn({k,v},a) ->
        if rem(v,2) != 0 do
          a + 1
        else
          a
        end
      end)
  |> M.is_palindrome
  |> IO.inspect
end

palindrome_check.("race car")
palindrome_check.("raace car")
