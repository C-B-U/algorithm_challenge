# 백준 알고리즘 2563 색종이 문제

canvas = [[0] * 100 for _ in range(100)]

n = int(input())

for _ in range(n):
    x, y = map(int, input().split())
    for i in range(x, x + 10):
        for j in range(y, y + 10):
            canvas[i][j] = 1

area = 0
for row in canvas:
    area += sum(row)

print(area)
