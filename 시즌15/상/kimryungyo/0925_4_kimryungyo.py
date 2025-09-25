# K부터 출발해서 가능한 시작 지점을 찾아주면 된다. 오버플로우 주의
# 초반에 방향 이상하게 잡았다가 많이 고생했다..

from sys import stdin, setrecursionlimit
input = stdin.readline
setrecursionlimit(250000)

N, K = map(int, input().split())
heights = list(map(int, input().split()))
graph = { i: [] for i in range(N) }

for _ in range(N - 1):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)

def dfs(now, before, min_height):
    for next in graph[now]:
        if next == before: continue

        if heights[next] >= min_height:
            print(1)
            quit()

        next_height = heights[next]
        next_min_height = (min_height - next_height) * 2 + next_height

        if next_min_height > 1000000: continue
        dfs(next, now, next_min_height)

dfs(K - 1, None, heights[K - 1])
print(0)