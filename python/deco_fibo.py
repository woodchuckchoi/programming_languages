def fibo_deco(func):
	res = {}

	def inner(*args):
		n = args[0]
		if res.get(n):
			return res.get(n)
		r = func(n)
		res[n] = r
		return r

	return inner

@fibo_deco
def fibo(n):
	if n < 3:
		return 1

	return fibo(n-1) + fibo(n-2)

if __name__ == '__main__':
	for i in range(100):
		print(fibo(i))

	# O(n)
