# 다이나믹 프로그래밍

dp = [[1, 0], [0, 1]]

def fibonacci(n):
    for _ in range(n - len(dp) + 1):
        dp.append([dp[-1][0] + dp[-2][0], dp[-1][1] + dp[-2][1]])
    return dp[n]

for _ in range(int(input())):
    print(*fibonacci(int(input())))
