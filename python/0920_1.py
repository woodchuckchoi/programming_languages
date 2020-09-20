import os
import time
glob = 0

def main():
	global glob
	target = 0
	print('It should be only printed once')
	pid = os.fork()
	if pid == 0:
		for _ in range(100000):
			target += 1
			glob += 1
		print('PID:0 Address of Target: {}'.format(hex(id(target))))
	else:
		for _ in range(100000):
			target -= 1
			glob -= 1
		print('PID:{} Address of Target: {}'.format(pid, hex(id(target))))
	print('Address of Target: {} Target Status: {}'.format(hex(id(target)), target))

if __name__ == '__main__':
	main()
	print('Global Value: {}'.format(glob))
