defmodule SimpleQueue.Application do
	use Application

	def start(_type, _args) do
		children = [
			SimpleQueue
		]

		opts = [strategy: :one_for_one, name: SimpleQueue.Supervisor]
		# Supervisor.start_link(children, opts)
		DynamicSupervisor.start_link(opts) # Dynamic Supervisor
	end
end
