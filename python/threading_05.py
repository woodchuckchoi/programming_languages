import threading
import time

def annoying(para):
    for i in range(3):
        print(str(para) * 10)
        time.sleep(0.1)

threads = list()

for i in range(10):
    threads.append(threading.Thread(target=annoying, args=(i,)))
    threads[i].start()

for i in threads:
    i.join()
