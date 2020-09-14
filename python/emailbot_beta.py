import threading
import multiprocessing
import time
import random

def waiting():
    sleep_term = random.randrange(1, 5)
    time.sleep(sleep_term)
    print(f'After {sleep_term}seconds of sleep, I woke up')

def main():
    t = multiprocessing.Process(target=waiting, daemon=True)
    start_time = time.time()
    t.start()
    while True:
        if time.time() - start_time > 3:
            break
        time.sleep(1)
    t.terminate()
    #how to kill a thread?

for i in range(5):
    print(f'{i}th try')
    main()
