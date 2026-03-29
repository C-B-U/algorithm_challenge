import sys
from collections import deque

input = sys.stdin.readline

n, m, v = map(int, input().split())
g = [[] for _ in range(n)]
visited = [False] * n

q = deque()
ans = []
for _ in range(m):
    a, b = map(int, input().split())

    g[a - 1].append(b - 1)
    g[b - 1].append(a - 1)


def dfs(e, r):
    visited[r] = True
    ans.append(r)

    for x in e:
        if not visited[x]:
            dfs(g[x], x)


def bfs(r):
    visited[r] = True

    q.append(r)
    while len(q) != 0:
        y = q.popleft()
        for x in g[y]:
            if not visited[x]:
                visited[x] = True
                q.append(x)

        ans.append(y + 1)


for j in range(n):
    g[j] = sorted(g[j])

dfs(g[v - 1], v - 1)
for i in range(len(ans)):
    ans[i] = str(ans[i] + 1)

print(" ".join(ans))
visited = [False] * n
ans.clear()

bfs(v - 1)
for i in range(len(ans)):
    ans[i] = str(ans[i])

print(" ".join(ans))
