# 점의 개수 N 입력 받기
N = int(input())

# 점의 위치 정보를 저장할 리스트 초기화
points = []

# N개의 점 위치 정보를 입력 받기
for _ in range(N):
    x, y = map(int, input().split())
    points.append((x, y))

# x좌표를 기준으로 오름차순 정렬하고, x좌표가 같으면 y좌표를 기준으로 오름차순 정렬
points.sort()

# 정렬된 점 위치 정보 출력
for point in points:
    print(point[0], point[1])