n = int(input())
dp = [0 for _ in range(n+1)]
dp[1] = 1

for i in range(2, n+1):
    j = 1
    x = 5
    while j ** 2 <= i:
        x = min(x, dp[i - j ** 2])
        j += 1

    dp[i] = x + 1


print(dp[n])
