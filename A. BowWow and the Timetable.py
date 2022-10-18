a = input()
x = 0
for ch in a:
	x *= 2
	if ch == '1':
		x += 1
x -= 1
res = 0
while(x > 0):
	res += 1
	x //= 4
print(res)