a = int(input())
res = 1
con = a
while con > 1:
	res = con * res
	con = con - 1
den = a
con = a
while con > 1:
	den = den * a
	con = con - 1
# print(res)
# print(den)
res = res * res * 10000000000 // den
go = str(res)
tam = len(go)
print(go[0:tam-10] + "." + go[tam-10:])