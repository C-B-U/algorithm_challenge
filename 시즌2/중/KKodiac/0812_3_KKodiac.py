# BOJ 24445 알고리즘 수업 - 너비 우선 탐색 2
from collections import deque, defaultdict
import sys
def solution():
    def bfs(graph, root, n):
        queue = deque([root])
        visited = [0] * (n+1)
        cur = 0
        while queue:
            n = queue.popleft()
            if not visited[n]:
                cur += 1
                visited[n] = cur
                for i in graph[n]:
                    if not visited[i]:
                        queue.append(i)

        return visited


    n, m, r = map(int, input().split())
    graph = defaultdict(list)
    for _ in range(m):
        u, v = map(int, sys.stdin.readline().rstrip().split())
        graph[u].append(v)
        graph[v].append(u)

    for key in graph:
        graph[key].sort(reverse=True)

    for node in bfs(graph, r, n)[1:]:
        print(node)

if '__main__' == __name__:
    solution()
