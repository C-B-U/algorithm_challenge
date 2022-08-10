import sys
input = sys.stdin.readline

n = int(input())
board = [list(input().strip()) for _ in range(n)]
answer = 0


def max_count(board: list):
    global n, answer

    for i in range(n):

        cnt = 1
        for j in range(n-1):
            if board[i][j] == board[i][j+1]:
                cnt += 1
            else:
                cnt = 1
            answer = max(answer, cnt)

        cnt = 1
        for j in range(n-1):
            if board[j][i] == board[j+1][i]:
                cnt += 1
            else:
                cnt = 1
            answer = max(answer, cnt)


def main():
    global n, board, answer

    for i in range(n):

        for j in range(n-1):
            if board[i][j] != board[i][j+1]:
                board[i][j], board[i][j+1] = board[i][j+1], board[i][j]
                max_count(board)
                board[i][j], board[i][j+1] = board[i][j+1], board[i][j]

            if board[j][i] != board[j+1][i]:
                board[j][i], board[j+1][i] = board[j+1][i], board[j][i]
                max_count(board)
                board[j][i], board[j+1][i] = board[j+1][i], board[j][i]

    print(answer)


if __name__ == "__main__":
    main()
