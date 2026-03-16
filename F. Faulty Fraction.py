a, b = input().split()
x = len(a)
y = len(b)
b = int(b)
for z in range(y + (x - y) // 2, y + (x - y) // 2 + 1):
    if(z <= 0 or z >= x):
        continue
    # print(z)
    # print(a[:z])
    # print(a[z:])
    # print(b)
    if(a[z] == '0'):
        continue
    v = int(a[z:])
    u = int(a[:z])
    if(u // v == b and u % v == 0):
        print(a[:z], a[z:])
        break