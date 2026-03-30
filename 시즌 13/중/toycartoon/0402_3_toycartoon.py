p = [[0 for _ in range(100)] for __ in range(100)]
for _ in range(int(input())):
    x, y = map(int, input().split())

    for i in range(y - 1, y + 9):
        for j in range(x - 1, x + 9):
            p[i][j] = 1

a = 0
for l in p:
    a += l.count(1)

print(a)
