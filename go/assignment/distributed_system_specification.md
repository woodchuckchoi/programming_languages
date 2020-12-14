Master & Worker Structure

1. Highly Available
    1. Spawn Workers - Master keeps checking workers' heartbeat. When the load becomes heavier or the number of workers decreases, the master spawns more workers.
    2. Direct Communication - Master only keeps track of the information about the workers, which worker has it. The data is handled by the worker (and a couple more which keep a replica of the data), hence the client communicates with the worker directly after the initial redirect from the master.

2. Durable
    1. Replica - Master checks how many replicas does an entry have. If less than N, replication is triggered. Master directs the worker who has the original data to send a copy to other workers.
    2. Savepoint - Master saves the information about the workers periodically. (onto other masters?)

* Inspired by GFS Paper