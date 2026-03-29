def print_board(board):
    for i in range(len(board)):
        for j in range(len(board[0])):
            print(board[i][j], end="")
        print()


time = int(input())
for t in range(time):
    m, n, k = map(int, input().split(" "))
    board = [[0 for j in range(m)] for i in range(n)]
    for i in range(k):
        x, y = map(int, input().split(" "))
        board[y][x] = -1

    def is_vailed_index(x, y):
        if 0 > x or x >= m:
            return False
        if 0 > y or y >= n:
            return False
        return True
    
    count = 0
    for i in range(n):
        for j in range(m):
            if board[i][j] <= -1:
                count += 1
                stack = [[i, j]]
                while True:
                    if len(stack) == 0:
                        break
                    y, x = stack.pop()
                    board[y][x] = 1
                    for xx, yy in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                        if not is_vailed_index(x + xx, y + yy):
                            continue
                        if board[y + yy][x + xx] <= -1:
                            stack.append([y + yy, x + xx])
    print(count)
