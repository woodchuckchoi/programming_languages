defmodule Mix.Tasks.Hello do
	use Mix.Task

	@shortdoc "Simply calls the Hello.say/0 function."
	def run(_) do
		# calling our Hello.say() function from earlier
		Mix.Task.run("app.start")
		Hello.say()
	end
end
