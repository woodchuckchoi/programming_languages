import Config

config :tube2, :formatter, ElixirSeries.WesternFormatter
# In application tube2, when :formatter is called, return ElixirSeries.WesternFormatter

import_config "#{Mix.env()}.exs"
# overwrites :formatter config with the content of dev.exs