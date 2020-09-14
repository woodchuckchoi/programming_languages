import socket
import threading
import queue

q = queue.Queue()
print_lock = threading.Lock()
HOST = '127.0.0.1'

def pscan(para):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        conn = s.connect((HOST, para))
        with print_lock:
            print(f'Port {para} is open!')
        conn.close()
    except:
        print(f'No luck at port {para}')
        pass

def threader():
    while True:
        worker = q.get()
        pscan(worker)
        q.task_done()

for i in range(10):
    t = threading.Thread(target=threader, daemon=True)
    t.start()

for worker in range(1, 101):
    q.put(worker)

q.join()
