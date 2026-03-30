from operator import ne
import sys
from collections import defaultdict, deque

input = sys.stdin.readline


def Distance(a, b):
    queue = deque()
    queue.append(a)
    visited = [False] * (n + 1)
    target_dist = [0] * (n + 1)
    visited[a] = True
    while queue:
        v = queue.popleft()
        if v == b:
            print(target_dist[v])
            return
        for next, dist in graph[v]:
            if not visited[next]:
                queue.append(next)
                visited[next] = True
                target_dist[next] += target_dist[v] + dist
                


n, m = map(int, input().split())
graph = defaultdict(list)

for _ in range(n-1):
    a, b, dist = map(int, input().split())
    graph[a].append((b, dist))
    graph[b].append((a, dist))

for _ in range(m):
    a, b = map(int, input().split())
    Distance(a, b)
