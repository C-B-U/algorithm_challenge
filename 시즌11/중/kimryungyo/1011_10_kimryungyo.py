# 풀이 : 지문에서 설명한대로 구현만 하면 된다

from sys import stdin
input = stdin.readline

N, M = map(int, input().split())
R, C, D = map(int, input().split())
grid = [ list(map(int, input().split())) for _ in range(N) ]
directions = [ (-1, 0), (0, 1), (1, 0), (0, -1) ]

y, x = R, C
cleaned = 0

while True:
    if grid[y][x] == 0:
        grid[y][x] = -1
        cleaned += 1
        continue

    around_cleaned = True
    for dy, dx in directions:
        ny, nx = y + dy, x + dx
        if (0 <= ny < N) and (0 <= nx < M):
            if grid[ny][nx] == 0:
                around_cleaned = False

    if around_cleaned is True:
        dy, dx = directions[D]
        ny, nx = y - dy, x - dx

        if not ((0 <= ny < N) and (0 <= nx < M)):
            break

        if grid[ny][nx] == 1:
            break

        y, x = ny, nx
        continue

    for i in range(4):
        D = D - 1 if D > 0 else 3
        dy, dx = directions[D]
        ny, nx = y + dy, x + dx

        if (0 <= ny < N) and (0 <= nx < M):
            if grid[ny][nx] == 0:
                y, x = ny, nx
                break
    
print(cleaned)