n = int(input())
ar = list(map(int, input().split()))
su = 0
a = 1
for x in ar:
	su += x
if su % 2 == 1:
	print("N")
else:
	su /= 2
	for i in range(n):
		ar.append(ar[i])
	sa = 0;
	to = 0;
	co = 0;
	for i in range(n):
		while to < 2 * n and sa < su:
			sa += ar[to]
			to += 1
		if sa == su:
			co += 1
		sa -= ar[i]
	if co >= 3:
		print("Y")
	else:
		print("N")
