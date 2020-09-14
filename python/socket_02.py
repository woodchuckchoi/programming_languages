import socket
import threading
from queue import Queue

print_lock = threading.Lock()

target = '127.0.0.1'

def port_scan(port):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        conn = s.connect((target, port))
        with print_lock:
            print(f'Port {port} is open!')

        conn.close()
    except:
        pass

def threader():
    while True:
        worker = q.get()
        portscan(worker)
        q.task_done()

q = Queue()
for x in range(30):
    t = threading.Thread(target=threader)
