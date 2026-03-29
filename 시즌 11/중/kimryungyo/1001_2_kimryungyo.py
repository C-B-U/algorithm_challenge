# 인접한 부분들을 확인한 후 모양을 결정하면 된다
# 입력의 최대 길이는 900줄이므로 빠른 입력이 필요

from sys import stdin
input = lambda: stdin.readline().rstrip()

broken = [ ['.'] * 3 ] * 3

def get_block(y, x):
    block = [ [ grid[s_y][s_x] for s_x in range(x * 3, x * 3 + 3) ] for s_y in range(y * 3, y * 3 + 3) ]
    return block

def repair_block(y, x):
    block = get_block(y, x)
    if block != broken: return None

    center_y = y * 3 + 1
    center_x = x * 3 + 1

    checked = False
    if x > 0:
        left = grid[center_y][center_x - 2]
        if left == "#":
            grid[center_y][center_x - 1] = "#"
            checked = True

    if x < M - 1:
        right = grid[center_y][center_x + 2]
        if right == "#":
            grid[center_y][center_x + 1] = "#"
            checked = True

    if y > 0:
        up = grid[center_y - 2][center_x]
        if up == "#":
            grid[center_y - 1][center_x] = "#"
            checked = True

    if y < N - 1:
        down = grid[center_y + 2][center_x]
        if down == "#":
            grid[center_y + 1][center_x] = "#"
            checked = True

    if checked: grid[center_y][center_x] = "#"


N, M = map(int, input().split())
grid = [ list(input()) for _ in range(N * 3) ]

for y in range(N):
    for x in range(M):
        repair_block(y, x)

for line in grid:
    print("".join(line))
