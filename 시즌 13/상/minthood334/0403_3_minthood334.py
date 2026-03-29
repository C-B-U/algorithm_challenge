import sys
sys.setrecursionlimit(10**6)

n, h, w = map(int, sys.stdin.readline().split())

# 각 층마다 방문할 할 최소/최대 호수 저장
min_max = [[w, 0] for _ in range(h + 1)]
max_f = 0
for _ in range(n):
    x, y = map(int, sys.stdin.readline().split())
    max_f = max(max_f, x)
    min_max[x][0] = min(min_max[x][0], y)
    min_max[x][1] = max(min_max[x][1], y)

# dp[x][d]: x층 이전 인덱스 y일 때 최소 비용, d = 0 이면 왼쪽, d = 1 이면 오른쪽
dp = [[None, None] for _ in range(h + 2)]

def dfs(x, y, d):
    if x == max_f + 1:
        return -100
    if dp[x][d] is not None:
        return dp[x][d]
    if min_max[x][1] == 0:
        dp[x][d] = dfs(x + 1, y, d) + 100
    else:
        L, R = min_max[x][0], min_max[x][1]
        cl = dfs(x + 1, L, 0) + abs(R - y)
        cr = dfs(x + 1, R, 1) + abs(L - y)
        dp[x][d] = min(cl, cr) + (R - L) + 100
    return dp[x][d]

#d = 0 왼족, d = 1 오른쪽
print(dfs(1, 1, 0))
