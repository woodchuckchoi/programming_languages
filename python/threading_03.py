import threading
import time

def sleeper(n, name):
    print(f'Hi my name is {name} I will sleep for {n} seconds.')
    time.sleep(n)
    print(f'This is {name} again, I just woke up from sleep')

threads_list = list()

for i in range(5):
    t = threading.Thread(target=sleeper, args=(5, f'Minge{i}'))
    threads_list.append(t)
    t.start()
    print(f'Minge{i} has started!')

for t in threads_list:
    t.join()
