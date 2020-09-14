defmodule ExampleTest do
  use ExUnit.Case
  doctest Example

  setup_all do
    {:ok, recipient: :world}
  end

  test "greets the world", state do
    assert Example.hello() == state[:recipient]
  end
end
