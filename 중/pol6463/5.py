from collections import deque
import graphlib
from numpy import tri

from sqlalchemy import true


n, m, start = map(int, input().split())

visited = [False] * (n + 1)

graph = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)


for i in range(len(graph)):
    graph[i].sort()

def dfs(start):
    print(start, end=' ')
    visited[start] = True
    for i in graph[start]:
        if not visited[i]:
            dfs(i)
            visited[i] = True

def bfs(start):
    queue = deque([start])
    visited[start] = True
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

dfs(start)
visited = [False] * (n + 1)
print()
bfs(start)
