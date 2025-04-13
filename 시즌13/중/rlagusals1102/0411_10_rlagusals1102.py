def solve(n):
    dp = [0] + [100000] * n

    for i in range(1, n + 1):
        j = 1
        while j * j <= i:
            dp[i] = min(dp[i], dp[i - j * j] + 1)
            j += 1

    return dp[n]

print(solve(int(input())))
