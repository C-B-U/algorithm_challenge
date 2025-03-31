from math import inf

n = int(input())
dp = [inf for _ in range(n+1)]

dp[1] = 0
for i in range(1, n+1):
    if i * 3 <= n:
        dp[i*3] = min(dp[i] + 1, dp[i*3])
    if i * 2 <= n:
        dp[i*2] = min(dp[i] + 1, dp[i*2])
    if i + 1 <= n:
        dp[i+1] = min(dp[i] + 1, dp[i+1])


print(dp[n])
