defmodule SendingProcess do
	def run(pid) do
		send(pid, :ping)
	end
end

defmodule TestReceive do
	use ExUnit.Case

	test "receives ping" do
		SendingProcess.run(self())
		assert_received :ping
	end
end
