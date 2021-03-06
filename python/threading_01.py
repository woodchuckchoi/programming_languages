import threading
from queue import Queue
import time

print_lock = threading.Lock()

def example_job(worker):
    time.sleep(0.5)
    with print_lock:
        print(threading.currentThread().name, worker)

def threader():
    while True:
        worker = q.get()
        example_job(worker)

        q.task_done()

q = Queue()

for x in range(10):
    t = threading.Thread(target = threader)
    t.daemon = True
    t.start()

start = time.time()

for worker in range(20):
    q.put(worker)

q.join()
print(f'Entire job took {time.time()-start} seconds.')
