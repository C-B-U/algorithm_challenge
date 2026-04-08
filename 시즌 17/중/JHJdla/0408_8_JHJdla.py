import sys
from bisect import bisect_left

input = sys.stdin.readline

n, k, x = map(int, input().split())
a = list(map(int, input().split()))

pre = [0] * (n + 1)
for i in range(1, n + 1):
    pre[i] = pre[i - 1] + a[i - 1] * x

suf = [0] * (n + 1)
for j in range(1, n + 1):
    suf[j] = suf[j - 1] + a[n - j]

INF = 10**18
min_work = INF


for i in range(n):  
    need = k - pre[i]
    if need <= 0:
        j = 0
    else:
        j = bisect_left(suf, need)

    if j <= n - 1 - i:
        min_work = min(min_work, i + j)

if min_work == INF:
    print(-1)
else:
    print(n - min_work)