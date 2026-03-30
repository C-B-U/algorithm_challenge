INF = 1000001

n, k = map(int, input().split())
dp = [INF] * (n + 1)
dp[0] = 0

for i in range(n):
    if i + 1 <= n:
        dp[i + 1] = min(dp[i + 1], dp[i] + 1)
    if i + i // 2 <= n:
        dp[i + i // 2] = min(dp[i + i // 2], dp[i] + 1)

print("minigimbob" if dp[n] <= k else "water")