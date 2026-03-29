N, M = map(int, input().split())
array = []
for _ in range(N):
    array.append(list(map(int, input().split())))

K = int(input())
for _ in range(K):
    i, j, x, y = map(int, input().split())
    result = 0
    for row in range(i-1, x):
        for col in range(j-1, y):
            result += array[row][col]
    print(result)

# N, M = map(int, input().split())
# arr = [list(map(int, input().split())) for _ in range(N)]

# K = int(input())
# dp = [[0] * (M+1) for _ in range(N+1)]

# for i in range(1, N+1):
#    for j in range(1, M+1):
#        dp[i][j] = arr[i-1][j-1] + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1]

#for _ in range(K):
#    i, j, x, y = map(int, input().split())
#    print(dp[x][y] - dp[x][j-1] - dp[i-1][y] + dp[i-1][j-1])
