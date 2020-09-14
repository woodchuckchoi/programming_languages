import socket
import sys

host = '127.0.0.1'
PORT = 4321

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    s.bind((host, PORT))
except socket.error as e:
    print(str(e))

s.listen(5)

conn, addr = s.accept()

print(f'Request received from : {conn} {addr}')

s.close()
