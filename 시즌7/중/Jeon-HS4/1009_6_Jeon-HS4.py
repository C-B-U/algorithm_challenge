def dfs(x, y):
    if x < 0 or x >= m or y < 0 or y >= n:
        return
    if land[x][y] == 0:
        return
    
    land[x][y] = 0  # 방문한 배추는 0으로 표시

    dfs(x+1, y)
    dfs(x-1, y)
    dfs(x, y+1)
    dfs(x, y-1)

T = int(input())

for _ in range(T):
    m, n, k = map(int, input().split())
    land = [[0] * n for _ in range(m)]

    bugs = 0
    
    for __ in range(k):
        x, y = map(int, input().split())
        land[x][y] = 1

    for i in range(m):
        for j in range(n):
            if land[i][j] == 1:
                dfs(i, j)
                bugs += 1

    print(bugs)
