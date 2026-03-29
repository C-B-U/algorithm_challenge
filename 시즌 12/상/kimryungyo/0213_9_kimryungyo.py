# [ 풀이 ] - 구현
# 문제에서 설명하는대로 풀면 된다.

def is_valid(board, row, col, num):
    # 가로줄에 중복된 숫자가 있는지 확인
    if num in board[row]:
        return False
    
    # 세로줄에 중복된 숫자가 있는지 확인
    if num in [board[i][col] for i in range(9)]:
        return False
    
    # 3x3 박스에 중복된 숫자가 있는지 확인
    start_row, start_col = 3 * (row // 3), 3 * (col // 3)
    for i in range(3):
        for j in range(3):
            if board[start_row + i][start_col + j] == num:
                return False
    
    return True

def find_empty(board):
    for i in range(9):
        for j in range(9):
            if board[i][j] == 0:
                return (i, j)
    return None

def solve_sudoku(board):
    empty = find_empty(board)
    if not empty:
        return True
    
    row, col = empty
    for num in range(1, 10):
        if is_valid(board, row, col, num):
            board[row][col] = num
            if solve_sudoku(board):
                return True
            board[row][col] = 0
    
    return False

board = [ list(map(int, input().split())) for _ in range(9) ]

solve_sudoku(board)

for row in board:
    print(" ".join(list(map(str, row))))