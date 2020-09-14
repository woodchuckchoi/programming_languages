import threading
import time

tmp = 3

def func1():
    global tmp
    for i in range(7):
        if tmp >= 3:
            tmp+= 2
            print('tmp += 2')
        else:
            print('waiting')
        time.sleep(2)

def func2():
    global tmp
    for i in range(10):
        if tmp >= 5:
            tmp += 1
            print('tmp += 1')
        else:
            print('waiting')
        time.sleep(1)

def func3():
    global tmp
    while True:
        if tmp >= 6:
            tmp -= 3
            print('tmp -= 3')
        else:
            print('waiting')
        time.sleep(3)

t1 = threading.Thread(target=func1)
t2 = threading.Thread(target=func2)
t3 = threading.Thread(target=func3, daemon=True)

t1.start()
t2.start()
t3.start()

t1.join()
t2.join()

print(f'The final value for tmp is {tmp}')
