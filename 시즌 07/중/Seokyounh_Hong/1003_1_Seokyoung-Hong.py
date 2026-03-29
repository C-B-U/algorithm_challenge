N, M = map(int, input().split())

board = []
for i in range(N):
    board.append(list(input()))

for i in range(N-7):
    for j in range(M-7):
        draw_W = 0
        draw_B = 0
        for row in range(i, i+8):
            for col in range(j, j+8):
                if (row+col) % 2 == 0:
                    if board[row][col] != 'W':
                        draw_W += 1
                    if board[row][col] != 'B':
                        draw_B += 1
                else:
                    if board[row][col] != 'B':
                        draw_W += 1
                    if board[row][col] != 'W':
                        draw_B += 1
        draw_min = min(draw_W, draw_B)
        if i == 0 and j == 0:
            result = draw_min
        elif result > draw_min:
            result = draw_min

print(result)
