def solution():
    N = int(input())
    board = [list(input()) for _ in range(N)]
    
    def search(board):
        longest_streak = 0
        for row in range(N):
            current_horizontal_streak = 1
            current_vertical_streak = 1
            for col in range(N-1):
                if board[row][col] == board[row][col+1]:
                    current_horizontal_streak += 1
                else:
                    longest_streak = max(longest_streak, current_horizontal_streak)
                    current_horizontal_streak = 1        
                if board[col][row] == board[col+1][row]:
                    current_vertical_streak += 1
                else:
                    longest_streak = max(longest_streak, current_vertical_streak)
                    current_vertical_streak = 1

            longest_streak = max(longest_streak, current_horizontal_streak, current_vertical_streak)

        return longest_streak


    def swap(board):
        answer = 0
        for row in range(N):
            for col in range(N-1):
                if board[row][col] != board[row][col+1]:
                    board[row][col], board[row][col+1] = board[row][col+1], board[row][col]
                    answer = max(answer, search(board))
                    board[row][col], board[row][col+1] = board[row][col+1], board[row][col]
                if board[col][row] != board[col+1][row]:
                    board[col][row], board[col+1][row] = board[col+1][row], board[col][row]
                    answer = max(answer, search(board))
                    board[col][row], board[col+1][row] = board[col+1][row], board[col][row]
        return answer

    print(swap(board))
    


if '__main__' == __name__:
    solution()