import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

HOST = '127.0.0.1'

def pscan(port):
    try:
        s.connect((HOST, port))
        return True
    except:
        return False

for x in range(1, 30):
    if pscan(x):
        print(f'Port {x} is open!')
    else:
        print(f'Port {x} is not open!')
