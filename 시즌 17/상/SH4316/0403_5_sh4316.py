from collections import deque

n, m = map(int, input().split(" "))

if m == 0:
    print(0)
    exit()
if n == 0:
    print(-1)
    exit()

p = []
__p = map(int, input().split(" "))
for v in __p:
    if v == 0:
        continue
    p.append(v)


MAX = 1000000000
LENGTH = 20000

dp = [MAX for i in range(LENGTH*2+3)] # 오류 나면 범위 늘리기
dp[0] = 0

c = len(p)
queue = deque([(0, v) for v in p])

while c != 0:
    i, v = queue.popleft()
    # print(i, dp[i], v)
    c -= 1

    if i > LENGTH or i < -LENGTH:
        continue
    if i == m:
        print(dp[i])
        exit()

    if dp[i+v] > dp[i] + 1:
        dp[i+v] = dp[i] + 1
        c += len(p)
        for k in p:
            queue.append((i+v, k))

if dp[m] == MAX:
    print(-1)
else:
    print(dp[m])
