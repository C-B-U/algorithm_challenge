# 백준 알고리즘 15723번 'n단 논법' https://www.acmicpc.net/problem/15723
from collections import deque

n = int(input())

graph = {}
for i in range(ord('a'), ord('z')+1):
    graph[chr(i)] = []

for _ in range(n):
    a, _, b = input().split()
    graph[a].append(b)

m = int(input())

def bfs(graph, start_v, final_v):
    visited = {key: False for key in graph}
    q = deque()
    q.append(start_v)
    visited[start_v] = True

    while q:
        cur_v = q.popleft()
        if cur_v == final_v:
            return True
        for next_v in graph[cur_v]:
            if not visited[next_v]:
                visited[next_v] = True
                q.append(next_v)
    return False

for _ in range(m):
    a, _, b = input().split()
    if bfs(graph, a, b):
        print('T')
    else:
        print('F')