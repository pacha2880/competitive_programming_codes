a = int(input())
res = 0
while a % 3 == 0:
    a //= 3
    res += 1
print(res)
if a == 1:
    print(res)
else:
    print(-1)