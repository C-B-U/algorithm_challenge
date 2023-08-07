X, Y, W, S = map(int, input().split())

# 1.  한 블록을 가로지르는 시간이 한 블록 가는데 걸리는 시간보다 짧은 경우
if S < W:
    better = (abs(X - Y) // 2) * S * 2
    ans = min(X, Y) * S + better + (abs(X - Y) % 2) * W
# 2. 한 블록을 가로지르는 시간이 두 블록 가는데 걸리는 시간보다 짧은 경우
elif S <= W*2:
    ans = min(X, Y)*S + abs(X-Y)*W
# 3. 한 블록을 가로지르는 시간이 두 블록 가는데 걸리는 시간보다 긴 경우
else:
    ans = (X+Y)*W

print(ans)
