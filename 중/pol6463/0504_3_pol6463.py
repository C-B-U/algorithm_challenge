n = int(input())

board = []
for _ in range(n):
    board.append(list(input()))


count = 0

def width():
    global count

    for i in range(n):
        countRow = 1
        for j in range(n - 1):
            if board[i][j] == board[i][j + 1]:
                countRow += 1
                count = max(count, countRow)
            else:
                countRow = 1

def height():
    for i in range(n):
        global count

        countColumn = 1
        for j in range(n - 1):
            if board[j][i] == board[j + 1][i]:
                countColumn += 1
                count = max(count, countColumn)
            else:
                countColumn = 1


for i in range(n):
    for j in range(n - 1):
        if board[i][j] != board[i][j + 1]:
            board[i][j], board[i][j + 1] = board[i][j + 1], board[i][j]
            width()
            height()
            board[i][j + 1], board[i][j] = board[i][j], board[i][j + 1]
        if board[j][i] != board[j + 1][i]:
            board[j][i], board[j + 1][i] = board[j + 1][i], board[j][i]
            width()
            height()
            board[j + 1][i], board[j][i] = board[j][i], board[j + 1][i]

print(count)