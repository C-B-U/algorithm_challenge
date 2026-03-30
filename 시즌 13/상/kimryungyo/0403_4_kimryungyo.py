# 우선 인접한 선수들끼리 실력차가 최소가 되도록 선수들을 실력 순으로 정렬한다.
# 정렬된 순서에서 연속 4명을 팀으로 구성할 때의 실력차(최대-최소)를 비용으로 보고,
# dp[i]를 i번째 선수부터 구성 가능한 (팀 수, 총 비용)으로 정의하여 DP를 진행한다.
# team 선택 시 연속된 4명을 팀으로 구성하고, skip 선택 시 해당 선수를 경기에서 제외한다.
# DP 복원 후, 팀에 포함되지 않은 선수의 원래 번호를 오름차순으로 출력한다.

n, *datas = map(int, open(0).read().split())
players = [(datas[i], i) for i in range(n)]
players.sort(key=lambda x: x[0])

dp = [(0, 0)] * (n + 1)         # dp[i] : (팀 수, 총 비용)
decision = [None] * (n + 1)     # decision[i] : 각 선수에 대한 선택, skip or team
dp[n] = (0, 0)

for i in range(n - 1, -1, -1):
    skip = dp[i + 1]
    best = skip
    best_decision = 'skip'
    if i + 3 < n:
        candidate = (1 + dp[i + 4][0], (players[i + 3][0] - players[i][0]) + dp[i + 4][1])
        if (candidate[0], -candidate[1]) > (best[0], -best[1]):
            best = candidate
            best_decision = 'team'
    dp[i] = best
    decision[i] = best_decision

total_cost = dp[0][1]

used = [False] * n
i = 0
while i < n:
    if decision[i] == 'team' and i + 3 < n:
        used[i] = used[i + 1] = used[i + 2] = used[i + 3] = True
        i += 4
    else:
        i += 1

skipped = [players[i][1] for i in range(n) if not used[i]]
skipped.sort()

print(total_cost)
print("\n".join(map(str, skipped)))