defmodule Tube2.MixProject do
  use Mix.Project

  def project do
    [
      app: :tube2,
      version: "0.1.0",
      elixir: "~> 1.10",
      start_permanent: Mix.env() == :prod,
      deps: deps(),

      # ExDoc
      name: "Tube2",
      soruce_url: "https://github.com/woodchuckchoi/elixir",
      hompage_url: "https://github.com/woodchuckchoi",
      docs: [
        main: "Tube2",
        extras: ["README.md"]
      ]
    ]
  end

  # Run "mix help compile.app" to learn about applications.
  def application do
    [
      extra_applications: [:logger]
    ]
  end

  # Run "mix help deps" to learn about dependencies.
  defp deps do
    [
      {:ecto, "~> 3.3.1"},
      {:ex_doc, "~> 0.21", only: :dev, runtime: false},
    ]
  end
end
