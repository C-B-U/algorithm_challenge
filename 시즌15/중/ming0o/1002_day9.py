import sys
input = sys.stdin.readline

MAXVALUE = int(1e7)
col = 3

def get_max_dp(board, row):
    dp = [[0] * col for _ in range(row)]
    dp[0] = board[0][:]

    for i in range(1, row):
        for j in range(col):
            dp[i][j] = board[i][j] + max(
                dp[i-1][k] for k in [j-1, j, j+1] if 0 <= k < col
            )

    return max(dp[-1])

def get_min_dp(board, row):
    dp = [[MAXVALUE] * col for _ in range(row)]
    dp[0] = board[0][:]

    for i in range(1, row):
        for j in range(col):
            dp[i][j] = board[i][j] + min(
                dp[i-1][k] for k in [j-1, j, j+1] if 0 <= k < col
            )

    return min(dp[-1])

def main():
    row = int(input())
    board = [list(map(int, input().split())) for _ in range(row)]
    max_answer = get_max_dp(board, row)
    min_answer = get_min_dp(board, row)
    print(max_answer, min_answer)

if __name__ == "__main__":
    main()
