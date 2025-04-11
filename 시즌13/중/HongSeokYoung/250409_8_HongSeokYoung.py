import sys
input = sys.stdin.readline

# 입력
n = int(input())
a, b = map(int, input().split())

points = set()
for _ in range(n):
    x, y = map(int, input().split())
    points.add((x, y))

count = 0

# 각 점을 좌하단으로 가정하고 나머지 3개 꼭짓점 확인
for x, y in points:
    if ((x + a, y) in points and
        (x, y + b) in points and
        (x + a, y + b) in points):
        count += 1

print(count)