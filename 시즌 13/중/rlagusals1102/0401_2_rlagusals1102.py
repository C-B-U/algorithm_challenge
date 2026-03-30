from collections import deque

def dfs(graph: list[list[int]], v: int, visited: list[bool]) -> None:
    visited[v] = True
    print(v, end=' ')
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

def bfs(graph: list[list[int]], v: int, visited: list[bool]) -> None:
    queue: deque = deque([v])
    visited[v] = True
    while queue:
        node: int = queue.popleft()
        print(node, end=' ')
        for i in graph[node]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True


n, m, v = map(int, input().split())

graph: list[list[int]] = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1, n + 1):
    graph[i].sort()

visited: list[bool] = [False] * (n + 1)
dfs(graph, v, visited)
print()

visited = [False] * (n + 1)
bfs(graph, v, visited)
print()
