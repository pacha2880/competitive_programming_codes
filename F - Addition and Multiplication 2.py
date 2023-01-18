n = int(input())
cs = list(map(int, input().split()))
ma = (0, 0, 0)
for i in range(1, 10):
    ma = max(ma, ((n // cs[i - 1], i, cs[i - 1])))
res = 0
mo = (0, 0)
for i in range(1, 10):
    if ma[2] + n % ma[2] >= cs[i - 1]:
        mo = max(mo, (i, cs[i - 1]))
n -= mo[1]
res += mo[0]
while n >= ma[2]:
    res = res * 10 + ma[1]
    n -= ma[2]
print(res)