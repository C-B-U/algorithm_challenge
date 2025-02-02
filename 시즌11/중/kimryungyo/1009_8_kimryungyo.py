# 풀이 : 그래프 탐색 (DFS, BFS)

from collections import deque

N, *stones, S = map(int, open(0).read().split())
visited = [ False ] * N
visited[S - 1] = True

count = 0
queue = deque([ S - 1 ])
while queue:
    pos = queue.popleft()
    count += 1

    jump = stones[pos]

    for next in [pos - jump, pos + jump]:
        if (0 <= next < N) and not visited[next]:
            visited[next] = True
            queue.append(next)

print(count)