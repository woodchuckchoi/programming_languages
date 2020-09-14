import threading
import queue

q = queue.Queue()
print_lock = threading.Lock()

def factorial(para):
    if not para == 1:
        return para * factorial(para-1)
    else:
        return 1

def threader():
    while True:
        worker = q.get()
        q.task_done()
        with print_lock:
            print(f'{worker}\'s factorial value is {factorial(worker)}!')

for i in range(10):
    t = threading.Thread(target=threader, daemon=True)
    t.start()

for worker in range(1, 61):
    q.put(worker)

q.join()
