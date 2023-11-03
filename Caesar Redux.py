cas = int(input())
for _ in range(cas):
    a = int(input())
    line = input()
    lin = line.split()
    for i in range(len(lin)):
        if(lin[i] == 'the'):
            a = -a
    res = ''
    for i in range(len(line)):
        if(line[i] != ' '):
            va = ord(line[i]) + a
            if(va < ord('a')):
                va += 26
            if(va > ord('z')):
                va -= 26
            res += chr(va)
        else:
            res += ' '
    print(res)
