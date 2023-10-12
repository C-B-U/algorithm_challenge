import sys
from collections import deque

def bfs(v):
    q = deque([v]) #큐 구현을 위해 deque 사용
    while q:
        v = q.popleft()
        if v == k:
            return visited[v]
        for i in (v-1, v+1, 2*v):
            if 0 <= i <= 100000 and not visited[i]:
                visited[i] = visited[v] + 1
                q.append(i)

n, k = map(int, sys.stdin.readline().split())
visited = [0 for i in range(100001)]
print(bfs(n))
