from bisect import bisect_left

picture, s = map(int ,input().split())
info = [[-float('INF'), 0]] + [list(map(int, input().split())) for _ in range(picture)]
dp = [0]*(picture+1)
info.sort(key=lambda x: (x[0], -x[1]))

for i in range(1, picture+1):
    s, e = 0, i - 1
    while s <= e:
        mid = (s+e)//2
        if info[mid][0] <= info[i][0] - s:
            tmp = mid
            s = mid + 1
        else:
            e = mid - 1

    dp[i] = max(dp[i-1], dp[tmp] + info[i][1])

print(dp)