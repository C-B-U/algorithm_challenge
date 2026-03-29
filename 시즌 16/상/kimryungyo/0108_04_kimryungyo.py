# [풀이]
# 첫번째 가스관에서 시작해 빵집까지 겹치지 않는 파이프 경로를 최대한 많이 만든다.
# 경로를 만들때는 (오른쪽 위, 오른쪽, 오른쪽 아래) 순서대로 진행해야 하는데,
# 이러면 위쪽으로 최대한 붙는 경로를 먼저 확보해 아래쪽 경로들이 막힐 가능성이 최소화된다.
# + 경로 탐색은 재귀 DFS로 구현

from sys import stdin, setrecursionlimit
setrecursionlimit(10000)
input = stdin.readline
R, C = map(int, input().split())

grid = []
for _ in range(R):
    line = input().strip()
    grid.append([ch == 'x' for ch in line])

dirs = (-1, 0, 1)  # 오른쪽 위, 오른쪽, 오른쪽 아래

def dfs(row, col):
    if col == C - 1:
        return True

    n_col = col + 1
    for dir in dirs:
        n_row = row + dir
        if 0 <= n_row < R and not grid[n_row][n_col]:
            grid[n_row][n_col] = True  # 점유 처리
            if dfs(n_row, n_col):
                return True
    return False

result = 0
for r in range(R):
    grid[r][0] = True  # 시작 칸 점유 처리
    if dfs(r, 0):
        result += 1

print(result)