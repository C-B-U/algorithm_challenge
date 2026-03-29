def tile_count(n):
    mod = 1000000007
    dp = [0] * (n + 1)
    dp[0], dp[1] = 1, 1

    for i in range(2, n + 1):
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % mod

    return dp[n]

def solve_with_bitmask(n):
    mod = 1000000007
    dp = [0] * (1 << n)

    def count_ways(mask):
        if mask == (1 << n) - 1:
            return 1

        if dp[mask] != 0:
            return dp[mask]

        ways = 0
        for i in range(n):
            if (mask & (1 << i)) == 0:
                if i + 1 < n and (mask & (1 << (i + 1))) == 0:
                    # 가로로 2x1 타일을 놓는 경우
                    ways = (ways + count_ways(mask | (1 << i) | (1 << (i + 1)))) % mod

                # 세로로 1x2 타일을 놓는 경우
                ways = (ways + count_ways(mask | (1 << i))) % mod

        dp[mask] = ways
        return ways

    return count_ways(0)

# 테스트 케이스 수 입력
T = int(input())

# 각 테스트 케이스에 대해 결과 출력
for _ in range(T):
    N = int(input())
    result = solve_with_bitmask(N)
    print(result)
