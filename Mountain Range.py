import sys
sys.setrecursionlimit(300000)
read = sys.stdin.buffer.readline
write = sys.stdout.buffer.write

table = []

def inispar(ar: list[(int, int)]):
    table.append(ar)
    n = len(ar)
    k = 0
    while (1 << k) < n:
        i = 0
        table.append([(0, 0)] * n)
        while i + (1 << k) < n:
            table[k + 1][i] = max(table[k][i], table[k][i + (1 << k)])
            i += 1
        k += 1

def query(b: int, e: int) -> tuple[int, int]:
    lev = (e - b + 1).bit_length() - 1
    return max(table[lev][b], table[lev][e - (1 << lev) + 1])

def f(b: int, e: int) -> int:
    if b > e:
        return 0
    if b == e:
        return 1
    las = e
    maxi, _ = query(b, e)
    res = 0
    while las >= b:
        may, po = query(b, las)
        if may != maxi:
            res = max(res, f(b, las))
            break
        res = max(res, f(po + 1, las))
        las = po - 1
    return res + 1

n = int(read())
ar = list(map(int, input().split()))
arr = [(ar[i], i) for i in range(n)]
inispar(arr)
print(f(0, n - 1))