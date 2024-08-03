n, m = map(int, input().split())
l = []
mini = []

for _ in range(n):
    l.append(input())

for a in range(n - 7):
    for i in range(m - 7):
        c1 = 0
        c2 = 0
        for b in range(a, a + 8):
            for j in range(i, i + 8):
                if (j + b)%2 == 0:
                    if l[b][j] != 'W':
                        c1 += 1  
                    if l[b][j] != 'B':
                        c2 += 1
                else :
                    if l[b][j] != 'B':
                        c1 += 1
                    if l[b][j] != 'W':
                        c2 += 1
        mini.append(c1)
        mini.append(c2)

print(min(mini))
