n = int(input())
data = list(map(int, input().split()))

dp = [0] * len(data)
dp[0] = data[0]

for i in range(1, len(data)):
    dp[i] = max(data[i], dp[i-1] + data[i])

print(max(dp))
