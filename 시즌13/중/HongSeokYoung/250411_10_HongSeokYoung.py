import sys
input = sys.stdin.readline

N = int(input())
dp = [0] + [i for i in range(1, N + 1)]  # dp[0] = 0, 나머지는 최대 i개로 초기화

for i in range(1, N + 1):
    j = 1
    while j * j <= i:
        if dp[i] > dp[i - j * j] + 1:
            dp[i] = dp[i - j * j] + 1
        j += 1

print(dp[N])