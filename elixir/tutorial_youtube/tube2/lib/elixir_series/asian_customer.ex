defmodule ElixirSeries.AsianCustomer do
    defstruct [:given_name, :sur_name]

    defimpl ElixirSeries.Greeter, for: __MODULE__ do
        def greet(customer) do
            "Greetings, #{customer.sur_name}#{customer.given_name}"
        end
    end
end