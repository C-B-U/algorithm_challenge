import sys
sys.setrecursionlimit(100000)


def dfs(x, y):
    if x < 0 or x >= m or y < 0 or y >= n:
        return False
    if field[y][x] == 0:
        return False
    else:
        field[y][x] = 0
        dfs(x-1, y)
        dfs(x+1, y)
        dfs(x, y-1)
        dfs(x, y+1)
        return True


t = int(input())

for i in range(t):
    m, n, k = map(int, input().split())

    field = [[0 for __ in range(m)] for _ in range(n)]
    for _ in range(k):
        a, b = map(int, input().split())
        field[b][a] = 1

    count = 0
    for i in range(m):
        for j in range(n):
            if dfs(i, j):
                count += 1
    print(count)
