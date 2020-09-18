# Spawn
spawn creates an elixir process, that is different to thread in a way an elixir process is much lighter and it communicates with other processes through messages.\
spawn_link, spawn_monitor will do the same job, but will also give the chance to check on the status of the process it branches.

---

# Agent
agent is an elixir process that stores the status.

---

# Task
task will be executed in the background, hence useful for expensive operations.

---

