# 백준 알고리즘 13699 '점화식' 문제
n = int(input())
dp = [0] * (n + 1)
dp[0] = 1  # 초기 조건

for i in range(1, n + 1):
    for j in range(i):
        dp[i] += dp[j] * dp[i - 1 - j]

print(dp[n])