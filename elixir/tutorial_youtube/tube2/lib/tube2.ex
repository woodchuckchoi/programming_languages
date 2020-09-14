defmodule Tube2 do
  @moduledoc """
  This is a sample app tutorial from Youtube.
  """
  @formatter Application.get_env(:tube2, :formatter)
  alias Tutorial.Employee

  @doc """
  Format the proper greeting.
  """
  @spec format(ElixirSeries.Formatter.t()) :: String.t()
  def format(employee), do: @formatter.format_name(employee) #WesternFormatter.format_name(employee)

  @doc """
  Create an employee or will return the changeset with errors.
  """
  @spec create_employee(map()) :: {:ok, Tutorial.Employee.t()} | {:error, Ecto.Changeset.t()}
  def create_employee(attrs) do
    case Employee.changeset(%Employee{}, attrs) do
      %{valid?: true} = changeset ->
        employee = 
          changeset
          |> Ecto.Changeset.apply_changes()
          |> Map.put(:id, Ecto.UUID.generate())
        {:ok, employee}
      changeset ->
        {:error, changeset}
    end
  end
  @moduledoc """
  Documentation for `Tube2`.
  """

  @doc """
  Hello world.

  ## Examples

      iex> Tube2.hello()
      :world

  """
end
