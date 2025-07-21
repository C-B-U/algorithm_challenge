# 백준 알고리즘 2578번 '빙고' https://www.acmicpc.net/problem/2578

# 빙고판 입력 받기
board = [list(map(int, input().split())) for _ in range(5)]

# 사회자가 부르는 숫자 입력 받기
calls = []
for _ in range(5):
    calls += list(map(int, input().split()))

# 숫자 위치 저장 (빠른 접근을 위해)
pos = {}
for i in range(5):
    for j in range(5):
        pos[board[i][j]] = (i, j)

# 체크 배열
marked = [[0]*5 for _ in range(5)]

# 빙고 줄 개수 확인 함수
def count_bingo():
    cnt = 0
    # 가로줄
    for i in range(5):
        if sum(marked[i]) == 5:
            cnt += 1
    # 세로줄
    for j in range(5):
        if sum(marked[i][j] for i in range(5)) == 5:
            cnt += 1
    # 대각선 (좌상→우하)
    if sum(marked[i][i] for i in range(5)) == 5:
        cnt += 1
    # 대각선 (우상→좌하)
    if sum(marked[i][4 - i] for i in range(5)) == 5:
        cnt += 1
    return cnt

# 사회자가 숫자를 부를 때마다 체크
for turn, number in enumerate(calls):
    x, y = pos[number]
    marked[x][y] = 1
    if count_bingo() >= 3:
        print(turn + 1)  # 몇 번째 숫자인지 출력 (0-index → +1)
        break