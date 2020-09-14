import socket
import threading


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
SERVER = 'localhost'

def pscan(port):
    try:
        s.connect((SERVER, port))
        print(f'{port} is open')
        return True
    except:
        print(f'No luck here at {port}')
        return False

threads = list()

for x in range(1, 26):
    threads.append(threading.Thread(target=pscan, args=(x,)))

print(f'{len(threads)} ports are being examined...')

for thread in threads:
    thread.start()
    thread.join()
