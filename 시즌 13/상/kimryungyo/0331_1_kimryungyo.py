# 원자의 에너지 상태들을 E[], 양성자 에너지 상태들을 C[]라고 할 때
# E_i, E_j가 서로 같은 에너지 상태에 있을 수 있으려면 |E_i - E_j| 가 C에 속해야한다.
# 해당 정보로 트리에서 다이나믹 프로그래밍을 진행하면 된다.

from sys import stdin
input = stdin.readline

N, M = map(int, input().split())
energies = [int(input().strip()) for _ in range(N)]
cell_energies = [int(input().strip()) for _ in range(M)]
allowed = set(cell_energies)

energy_to_index = {e: i for i, e in enumerate(energies)}

graph = [[] for _ in range(N)]
for e in energy_to_index:
    i = energy_to_index[e]
    for d in allowed:
        if e + d in energy_to_index:
            j = energy_to_index[e + d]
            graph[i].append(j)
            graph[j].append(i)

visited = [False] * N
dp = [[0, 0] for _ in range(N)]

def dfs(u, parent):
    visited[u] = True
    dp[u][1] = energies[u]
    dp[u][0] = 0
    for v in graph[u]:
        if v == parent:
            continue
        if not visited[v]:
            dfs(v, u)
            
        dp[u][1] += dp[v][0]
        dp[u][0] += max(dp[v][0], dp[v][1])

answer = 0
for i in range(N):
    if not visited[i]:
        dfs(i, -1)
        answer += max(dp[i][0], dp[i][1])

print(answer)