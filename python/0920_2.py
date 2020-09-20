from threading import Thread
target = 0

def plus_one():
	global target
	for _ in range(100000):
		target += 1

def minus_one():
	global target
	for _ in range(100000):
		target -= 1

def main():
	threads = []
	threads.append(Thread(target=plus_one))
	threads.append(Thread(target=minus_one))
	for thread in threads:
		thread.start()
	for thread in threads:
		thread.join()
	print(target)

if __name__ == '__main__':
	main()
