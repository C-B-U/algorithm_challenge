# 백준 알고리즘 2580번 '스도쿠' https://www.acmicpc.net/problem/2580

import sys
input = sys.stdin.readline

board = [list(map(int, input().split())) for _ in range(9)]
blanks = [(i, j) for i in range(9) for j in range(9) if board[i][j] == 0]

# 행, 열, 박스별로 숫자 사용 여부 저장
row = [[False]*10 for _ in range(9)]
col = [[False]*10 for _ in range(9)]
box = [[False]*10 for _ in range(9)]

# 초기 상태 반영
for i in range(9):
    for j in range(9):
        num = board[i][j]
        if num != 0:
            row[i][num] = True
            col[j][num] = True
            box[(i//3)*3 + (j//3)][num] = True

def solve(idx):
    if idx == len(blanks):
        for r in board:
            print(*r)
        sys.exit(0)

    x, y = blanks[idx]
    b = (x // 3) * 3 + (y // 3)

    for num in range(1, 10):
        if not row[x][num] and not col[y][num] and not box[b][num]:
            # 숫자 배치
            board[x][y] = num
            row[x][num] = col[y][num] = box[b][num] = True

            solve(idx + 1)

            # 백트래킹 (원상 복구)
            board[x][y] = 0
            row[x][num] = col[y][num] = box[b][num] = False

solve(0)