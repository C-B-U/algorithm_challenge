def solve(n: int) -> int:
    dp: list[int] = [0] * (n+1)

    for i in range(2, n+1):
        dp[i] = min([dp[i-1]] + [dp[i//j] for j in(2,3) if i%j == 0]) +1

    return dp[n]

print(solve(int(input())))
