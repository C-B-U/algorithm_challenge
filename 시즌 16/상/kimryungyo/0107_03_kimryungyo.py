# DP
MOD = 1000000
N = int(input())

# dp[지각][연속결석]
dp = [[0] * 3 for _ in range(2)]
dp[0][0] = 1

# 하루씩 늘려가며 DP 계산
for _ in range(N):
    next = [[0] * 3 for _ in range(2)]
    for late in range(2):
        for skip in range(3):
            v = dp[late][skip]
            if v == 0: continue

            next[late][0] = (next[late][0] + v) % MOD

            if late == 0:
                next[1][0] = (next[1][0] + v) % MOD

            if skip < 2:
                next[late][skip + 1] = (next[late][skip + 1] + v) % MOD

    dp = next

ans = 0
for late in range(2):
    for skip in range(3):
        ans = (ans + dp[late][skip]) % MOD

print(ans)
