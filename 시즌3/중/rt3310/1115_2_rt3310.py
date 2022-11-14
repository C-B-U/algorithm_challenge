t = int(input())

for _ in range(t):
    n = int(input())
    
    if n == 0:
        print(1, 0)
        continue
    if n == 1:
        print(0, 1)
        continue

    dp = [[0] * (n+1), [0] * (n+1)]
    dp[0][0] = 1
    dp[1][1] = 1
    
    for i in range(2, n+1):
        dp[0][i] = dp[0][i-1] + dp[0][i-2]
        dp[1][i] = dp[1][i-1] + dp[1][i-2]

    print(dp[0][-1], dp[1][-1])