import selectors
import socket

HOST = '127.0.0.1'
PORT = 65432

sel = selectors.DefaultSelector()

lsock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
lsock.bind((HOST, PORT))
lsock.listen()
print(f'Listening on {HOST} : {PORT}')
lsock.setblocking(False)

sel.register(lsock, selectors.EVENT_READ, data=None)
