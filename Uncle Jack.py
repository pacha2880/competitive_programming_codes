while True:
	n, d = map(int, input().split())
	if n == 0:
		break
	res = 1;
	for x in range(d):
		res *= n
	print(res)