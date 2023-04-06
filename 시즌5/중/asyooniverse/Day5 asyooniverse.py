import sys
input = sys.stdin.readline

m, n, k = map(int, input().split())
board = [[0] * n for i in range(m)]
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
cnt = []

for _ in range(k):
    bottom_x, bottom_y, top_x, top_y = map(int, input().split())
    for i in range(bottom_y, top_y): # 2, 4
        for k in range(bottom_x, top_x): # 0, 4
            board[i][k] = 1
# bfs 시작
for i in range(m):
    for j in range(n):
        if board[i][j] == 0: # 시작이 비어있으면
            count = 1 # 일단 카운트 하나 세주고
            board[i][j] = 1 # 채워줌
            queue = [[i, j]] # 큐 만들면서 start
            while queue:
                x, y = queue[0][0], queue[0][1]
                del queue[0]
                for idx in range(4):
                    # 상하좌우 탐색
                    x1 = x + dx[idx] 
                    y1 = y + dy[idx]
                    # 범위 체크 & 비워진 공간일 때만 방문
                    if 0 <= x1 < m and 0 <= y1 < n and board[x1][y1] == 0:
                        # 방문 했으니 1 대입
                        board[x1][y1] = 1
                        count += 1
                        queue.append([x1, y1])
            cnt.append(count)
            
print(len(cnt))
cnt.sort()
for i in cnt:
    print(i, end=' ')