# 다익스트라로 최단 경로를 찾으며 f(x)들을 구한다.

from heapq import heappop, heappush
from sys import stdin
input = stdin.readline

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

graph = [[] for _ in range(N)]

dist = [float('inf')] * N
heap = []

for idx in range(N):
    left = idx - A[idx]
    right = idx + A[idx]

    if 0 <= left < N:
        graph[left].append(idx)
    if 0 <= right < N:
        graph[right].append(idx)

    if left < 0 or right >= N:
        dist[idx] = B[idx]
        heappush(heap, (B[idx], idx))

while heap:
    cur_dist, cur = heappop(heap)

    if dist[cur] != cur_dist:
        continue

    for prev in graph[cur]:
        next_dist = cur_dist + B[prev]

        if next_dist < dist[prev]:
            dist[prev] = next_dist
            heappush(heap, (next_dist, prev))

print(*dist)
