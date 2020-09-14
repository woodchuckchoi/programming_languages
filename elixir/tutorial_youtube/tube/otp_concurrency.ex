defmodule SimpleQueue do
	use GenServer

	@doc """
	큐로 프로세스를 연결하세요. 이것은 헬퍼 함수 입니다.
	"""
	def start_link(state \\ []) do
		GenServer.start_link(__MODULE__, state, name: __MODULE__)
	end

	@doc """
	GenServer.handle_call/3 callback
	"""
	def handle_call(:dequeue, _from, [value | state]) do
		{:reply, value, state}
	end

	def handle_call(:dequeue, _from, []), do: {:reply, nil, []}

	def handle_call(:queue, _from, state), do: {:reply, state, state}

	def queue, do: GenServer.call(__MODULE__, :queue)
	def enqueue(value), do: GenServer.cast(__MODULE__, {:enqueue, value})
	def dequeue, do: GenServer.call(__MODULE__, :dequeue)
	
	@doc """
	GenServer.handle_cast/2 callback
	"""
	def handle_cast({:enqueue, value}, state) do
		{:noreply, state ++ [value]}
	end

	@doc """
	GenServer.init/1 callback
	"""
	def init(state), do: {:ok, state}
end
