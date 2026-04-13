# BFS를 이용해 가능한 최소 조합을 찾는다.

from collections import deque
from sys import stdin
input = stdin.readline

N, M = map(int, input().split())
if N == 0: print(0 if M == 0 else -1); quit()

coins = list(map(int, input().split()))

# 금액 범위가 -10000 ~ 10000 이므로, 10000을 더해 배열 인덱스로 사용한다.
OFFSET = 10000

# dist[x + OFFSET] = 금액 x를 만드는 데 필요한 최소 동전 수
dist = [-1] * 20001
dist[OFFSET] = 0
queue = deque([0])

# 0원에서 시작해 동전을 하나씩 더하는 BFS를 하면 최소 동전 개수를 먼저 찾는다.
while queue:
    cur = queue.popleft()

    for coin in coins:
        nxt = cur + coin
        if nxt < -10000 or nxt > 10000:
            continue
        if dist[nxt + OFFSET] != -1:
            continue

        dist[nxt + OFFSET] = dist[cur + OFFSET] + 1
        queue.append(nxt)

print(dist[M + OFFSET])
