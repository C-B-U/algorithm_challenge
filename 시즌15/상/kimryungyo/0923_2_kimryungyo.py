# 학생 i의 순위를 알기 위해서는, i보다 작은 학생 수 + 큰 학생 수 = N-1 이어야 한다.
# 그래프 탐색으로 i번 학생보다 키가 작은 학생의 수와 큰 학생의 수를 구해주면 된다.
# O(n ^ 2) / N(2 <= N <= 500) 이므로 파이썬에서도 충분히 돌아간다.

from sys import stdin
from collections import deque
input = stdin.readline

N, M = map(int, input().split())
GRAPH  = [[] for _ in range(N + 1)]
GRAPH_REV = [[] for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    GRAPH[a].append(b)
    GRAPH_REV[b].append(a)

def bfs_count(adj, s):
    visited = [False] * (N + 1)
    queue = deque([s])
    visited[s] = True
    count = 0
    while queue:
        node = queue.popleft()
        for next in adj[node]:
            if not visited[next]:
                visited[next] = True
                count += 1
                queue.append(next)
    return count

answer = 0
for i in range(1, N + 1):
    taller_cnt  = bfs_count(GRAPH, i)
    shorter_cnt = bfs_count(GRAPH_REV, i)
    if taller_cnt + shorter_cnt == N - 1:
        answer += 1

print(answer)