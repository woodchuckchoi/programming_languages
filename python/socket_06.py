import socket
import threading
# import queue
# I won't use queue here, I think queue is useful when processing a number of things with limited resources, but in the network
# environment, or just in my case, I want to have as many threads as the clients. One client will have one thread in this server.
# is it too idealistic? It might never be used in production. Even so...

def pong(conn, addr):
    conn.send('This is Hyuck\'s server, what can I do for you?'.encode())
    while True:
        data = conn.recv(2048).decode()
        if not data:
            break
        conn.sendall(f'{addr[0]} : {data}...'.encode())
        # why is sendall, instead of send used here? because there might be multi-session users?
    conn.close()

HOST = '127.0.0.1'
PORT = 4321

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    s.bind((HOST, PORT))
except socket.error as e:
    print(str(e))

s.listen(5)
print('Waiting for connection...')

while True:
    conn, addr = s.accept()
    print(f'{addr[0]}:{addr[1]} has connected...')
    t = threading.Thread(target = pong, args = (conn, addr))
    t.start()

s.close()
