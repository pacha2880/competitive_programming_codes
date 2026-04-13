import sys

read = sys.stdin.buffer.readline
write = sys.stdout.buffer.write

n = int(read())
grid = [read().strip() for _ in range(n)]

# Current frontier on diagonal s, represented only by column indices y
cur = [0]

# stamp[y] == current_mark means column y on the next diagonal was already added
stamp = [0] * n

ans = bytearray([grid[0][0]])
last = n - 1
total_steps = 2 * n - 2
g = grid
st = stamp

for s in range(total_steps):
    mark = s + 1
    best = 255
    nxt = []
    append = nxt.append

    for y in cur:
        x = s - y

        # Move down: (x+1, y)
        if x != last and st[y] != mark:
            st[y] = mark
            c = g[x + 1][y]
            if c < best:
                best = c
                nxt = [y]
                append = nxt.append
            elif c == best:
                append(y)

        # Move right: (x, y+1)
        ny = y + 1
        if ny != n and st[ny] != mark:
            st[ny] = mark
            c = g[x][ny]
            if c < best:
                best = c
                nxt = [ny]
                append = nxt.append
            elif c == best:
                append(ny)

    cur = nxt
    ans.append(best)

write(ans + b"\n")