defmodule School.User do
	# @enforce_keys [:name, :roles]
	@derive {Inspect, only: [:name]}
	defstruct name: nil, roles: []
end
