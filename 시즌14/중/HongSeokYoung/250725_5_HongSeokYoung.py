# 백준 알고리즘 14891번 '톱니바퀴' https://www.acmicpc.net/problem/14891

from collections import deque

# 입력
gears = [deque(input().strip()) for _ in range(4)]
k = int(input())

def rotate(gear, direction):
    if direction == 1:  # 시계 방향
        gear.appendleft(gear.pop())
    else:  # 반시계 방향
        gear.append(gear.popleft())

for _ in range(k):
    num, dir = map(int, input().split())
    num -= 1  # 인덱스 보정

    # 각 톱니 회전 방향 초기화
    directions = [0, 0, 0, 0]
    directions[num] = dir

    # 왼쪽 톱니 확인
    for i in range(num - 1, -1, -1):
        if gears[i][2] != gears[i + 1][6]:
            directions[i] = -directions[i + 1]
        else:
            break

    # 오른쪽 톱니 확인
    for i in range(num + 1, 4):
        if gears[i - 1][2] != gears[i][6]:
            directions[i] = -directions[i - 1]
        else:
            break

    # 실제 회전
    for i in range(4):
        if directions[i] != 0:
            rotate(gears[i], directions[i])

# 점수 계산
score = 0
for i in range(4):
    if gears[i][0] == '1':
        score += (1 << i)

print(score)