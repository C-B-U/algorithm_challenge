from collections import deque


def bfs():
    q = deque()
    q.append(n)
    while q:
        current = q.popleft()
        if current == k:
            return
        for i in (current-1, current+1, current*2):
            if 0 <= i < (10**5+1) and dp[i] == 0:
                dp[i] = dp[current]+1
                q.append(i)


n, k = map(int, input().split())
dp = [0]*(10**5+1)

bfs()
print(dp[k])
