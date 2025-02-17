# [ 풀이 ] - 위상 정렬 기초 문제
# 기본적인 위상 정렬을 구현하면 된다
# 예전에 풀었던 코드 제출

from collections import deque
from sys import stdin
input = lambda: stdin.readline().rstrip()

N, M = map(int, input().split())

in_degree = { num: 0 for num in range(1, N + 1) }
out_degree = { num: set() for num in range(1, N + 1) }

for _ in range(M):
    a, b = map(int, input().split())
    in_degree[b] += 1
    out_degree[a].add(b)

queue = deque()
for num in range(1, N + 1):
    if in_degree[num] == 0:
        queue.append(num)

order = []
while queue:
    vertex = queue.popleft()
    order.append(vertex)
    
    for next in out_degree[vertex]:
        in_degree[next] -= 1
        if in_degree[next] == 0:
            queue.append(next)

print(" ".join(map(str, order)))