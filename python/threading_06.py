import socket
import threading
from queue import Queue

print_lock = threading.Lock()

target = 'localhost'

def portscan(port):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        conn = s.connect((target, port))
        with print_lock:
            print(f'Port {port} is open!')
        conn.close()
    except:
        pass

threads = list()

for work in range(1, 100):
    threads.append(threading.Thread(target=portscan, args=(work,), daemon=True))
    threads[work-1].start()
