import sys

input = sys.stdin.readline

n, m = map(int, input().split())

arr = []
dp_prev = [0] * m
dp_curr = [0] * m

for _ in range(n):
    arr.append(list(map(int, list(input().rstrip()))))

answer = 0
for i in range(n):
    for j in range(m):
        if i == 0 or j == 0:
            dp_curr[j] = arr[i][j]
        elif arr[i][j] == 0:
            dp_curr[j] = 0
        else:
            dp_curr[j] = min(dp_prev[j - 1], dp_prev[j], dp_curr[j - 1]) + 1
        answer = max(dp_curr[j], answer)

    dp_prev, dp_curr = dp_curr, dp_prev 

print(answer * answer)
