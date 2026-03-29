def flip(matrix, x, y):
    for i in range(3):
        for j in range(3):
            matrix[x + i][y + j] ^= 1

n, m = map(int, input().split())
a = [list(map(int, input().strip())) for _ in range(n)]
b = [list(map(int, input().strip())) for _ in range(n)]

cnt = 0

if n < 3 or m < 3:
    cnt = -1 if a != b else 0
else:
    for i in range(n - 2):
        for j in range(m - 2):
            if a[i][j] != b[i][j]:
                flip(a, i, j)
                cnt += 1
    
    if a != b:
        cnt = -1

print(cnt)
