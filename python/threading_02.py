2import threading

def input1():
    tmp = input('What do you want?')
    print(f'Really? {tmp}? ...You sick bastard...')

def input2():
    tmp = input('What else do you want?')
    print(f'{tmp}? I\'m speechless... Never talk to me again')

t1 = threading.Thread(target=input1)
t2 = threading.Thread(target=input2)

t1.start()
t2.start()

'''
To see what's going to happen, when there are multiple threads that need the same kind of input, which is the input function here.
'''
