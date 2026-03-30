# 기초 DP

T = int(input())
for _ in range(T):
    n = int(input())
    coins = list(map(int, input().split()))
    target = int(input())
    
    dp = [0] * (target + 1)
    dp[0] = 1
    
    for coin in coins:
        for j in range(coin, target + 1):
            dp[j] += dp[j - coin]
    
    print(dp[target])