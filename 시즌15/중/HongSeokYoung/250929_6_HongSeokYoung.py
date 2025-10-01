# 백준 알고리즘 2468번 '안전 영역' https://www.acmicpc.net/problem/2468

import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
max_height = max(map(max, board))

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(x, y, h, visited):
    q = deque()
    q.append((x, y))
    visited[x][y] = True
    while q:
        cx, cy = q.popleft()
        for i in range(4):
            nx, ny = cx + dx[i], cy + dy[i]
            if 0 <= nx < n and 0 <= ny < n:
                if not visited[nx][ny] and board[nx][ny] > h:
                    visited[nx][ny] = True
                    q.append((nx, ny))

result = 0
for h in range(max_height + 1):  # 비의 높이 0부터
    visited = [[False]*n for _ in range(n)]
    count = 0
    for i in range(n):
        for j in range(n):
            if not visited[i][j] and board[i][j] > h:
                bfs(i, j, h, visited)
                count += 1
    result = max(result, count)

print(result)