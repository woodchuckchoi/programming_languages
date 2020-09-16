defmodule Example.MixProject do
  use Mix.Project

  def project do
    [
      app: :example,
      version: "0.1.0",
      elixir: "~> 1.10",
      start_permanent: Mix.env() == :prod,
      deps: deps(),
      escript: escript(),
    ]
  end

  defp escript do
    [main_module: Example.CLI]
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
		{:phoenix, "~> 1.1 or ~> 1.2"},
		{:phoenix_html, "~> 2.3"},
		{:cowboy, "~> 1.0", only: [:dev, :test]},
		{:slime, "~> 0.14"},
		{:ex_doc, "~> 0.21", only: :dev, runtime: false},
		{:png, github: "yuce/png"},
    ]
  end
end
