# 층간 이동 비용은 100초, 같은 층 내 이동 비용은 칸당 1초이다.
# 각 층의 최대 호수가 100이므로, 위층으로 올라갔다가 다시 내려오는 전략은 절대 최적해가 될 수 없다.

# 즉, 한 층씩 순차적으로 올라가면서, 그 층에서 방문해야 하는 모든 방을 처리한 후 다음 층으로 이동하는 방식이 최적이다.

# 층을 올라갈 때는 해당 층의 방문 할 모든 방에 방문 후 올라가야하기 때문에
# 가장 왼쪽에 위치한 방에서 올라가거나 가장 오른쪽에 위치한 방에서 올라가는 두 가지 경우만 고려하면 된다.

# 따라서 DP[1000][2] 테이블을 이용하여, 각 측까지 도달하는 최소 비용을 계산하면 최적해를 구할 수 있다.
# DP[FLOOR][POS]는 FLOOR 층에서 방문해야 하는 방들을 모두 처리한 후, POS = 0 (왼쪽) 또는 1 (오른쪽) 위치에서 끝났을 때의 최소 비용을 의미한다.

from sys import stdin
input = stdin.readline

N, H, W = map(int, input().split())
floor_dict = {}
for _ in range(N):
    x, y = map(int, input().split())
    if x not in floor_dict:
        floor_dict[x] = [y, y]
    else:
        floor_dict[x][0] = min(floor_dict[x][0], y)
        floor_dict[x][1] = max(floor_dict[x][1], y)

floors = sorted(floor_dict.keys())

dp = [[0,0] for _ in range(len(floors))]

f = floors[0]
L, R = floor_dict[f]
d = R - L

vertical_cost = (f - 1) * 100

cost_to_left = min(abs(1 - R) + d, abs(1 - L) + 2 * d)
cost_to_right = min(abs(1 - L) + d, abs(1 - R) + 2 * d)
dp[0][0] = vertical_cost + cost_to_left
dp[0][1] = vertical_cost + cost_to_right

prev_floor = f

for i in range(1, len(floors)):
    f = floors[i]
    L, R = floor_dict[f]
    d = R - L
    
    vertical_cost = (f - prev_floor) * 100
    
    new_left = new_right = float('inf')
    
    for prev_pos, prev_cost in [(floor_dict[floors[i-1]][0], dp[i-1][0]), (floor_dict[floors[i-1]][1], dp[i-1][1])]:
        cost_left = min(abs(prev_pos - R) + d, abs(prev_pos - L) + 2 * d)
        new_left = min(new_left, prev_cost + vertical_cost + cost_left)
        
        cost_right = min(abs(prev_pos - L) + d, abs(prev_pos - R) + 2 * d)
        new_right = min(new_right, prev_cost + vertical_cost + cost_right)
        
    dp[i][0] = new_left
    dp[i][1] = new_right
    prev_floor = f

ans = min(dp[-1][0], dp[-1][1])
print(ans)