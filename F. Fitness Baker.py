import sys
inputs = sys.stdin.read().splitlines()
for inp in inputs:
	a, b = map(int, inp.split())
	res = 0
	for i in range(1, a + 1):
		res += i * b ** i
	print(res)
