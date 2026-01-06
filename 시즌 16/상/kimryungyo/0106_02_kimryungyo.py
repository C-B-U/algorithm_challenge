# 벨만포드 알고리즘 기초 문제

from sys import stdin
input = stdin.readline
N, M = map(int, input().split())

edges = []
for _ in range(M):
    a, b, c = map(int, input().split())
    edges.append((a, b, c))

INF = float('inf')
dist = [ INF ] * (N + 1)
dist[1] = 0

for _ in range(N - 1):
    updated = False
    for u, v, w in edges:
        if dist[u] != INF and dist[v] > dist[u] + w:
            dist[v] = dist[u] + w
            updated = True
    if not updated:
        break

n_cycle = False
for u, v, w in edges:
    if dist[u] != INF and dist[v] > dist[u] + w:
        n_cycle = True
        break

if n_cycle:
    print(-1)
else:
    for city in range(2, N + 1):
        if dist[city] == INF:
            print(-1)
        else:
            print(dist[city])