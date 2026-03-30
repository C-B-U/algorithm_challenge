import sys
n, k = map(int, sys.stdin.readline().split())
stone = list(map(int, sys.stdin.readline().split()))

dp = [float('inf')] * n

for i in range(1, n):
    for j in range(0, i):
        if(j != 0 and dp[j] > k):
            continue
        power =  (i-j) * (abs(stone[j] - stone[i]) + 1)
        dp[i] = min(dp[i], power)

if dp[-1] > k:
    print("NO")

else:
    print("YES")