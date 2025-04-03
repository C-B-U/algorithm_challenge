# 백준 알고리즘 2563번 '색종이' https://www.acmicpc.net/problem/2563

# 도화지 크기 설정
canvas = [[0] * 100 for _ in range(100)]

# 색종이 수 입력
n = int(input())

# 색종이 위치 입력 및 도화지에 색칠
for _ in range(n):
    x, y = map(int, input().split())
    for i in range(x, x + 10):
        for j in range(y, y + 10):
            canvas[i][j] = 1

# 색칠된 영역 계산
area = 0
for row in canvas:
    area += sum(row)

print(area)