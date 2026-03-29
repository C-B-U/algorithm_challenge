n, m = map(int, input().split())
board = [input() for _ in range(n)]

def paint(x, y, color):
    repaints = 0
    for i in range(8):
        for j in range(8):
            if (i + j) % 2 == 0:
                if board[x + i][y + j] != color:
                    repaints += 1
            else:
                if board[x + i][y + j] == color:
                    repaints += 1
    return repaints

min_repaints = float('inf')
for i in range(n - 7):
    for j in range(m - 7):
        min_repaints = min(min_repaints, paint(i, j, 'B'), paint(i, j, 'W'))

print(min_repaints)
