n = int(input())

dp = [[0] * n, [0] * n, [0] * n]

dp[0][0], dp[1][0], dp[2][0] = list(map(int, input().split()))

for i in range(1, n):
    row = list(map(int, input().split()))
    dp[0][i] = min(dp[1][i-1] + row[0], dp[2][i-1] + row[0])
    dp[1][i] = min(dp[0][i-1] + row[1], dp[2][i-1] + row[1])
    dp[2][i] = min(dp[0][i-1] + row[2], dp[1][i-1] + row[2])
    
print(min(dp[0][-1], dp[1][-1], dp[2][-1]))