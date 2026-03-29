# [ 풀이 ]
# CCW(Counter ClockWise) 알고리즘을 이용한 선분 교차 판별 문제
# p1과 p2를 연결하는 선분과 교차하는 선분이 짝수개면 B회사가 모두 가져갈 수 있다.
# 골드 1 까지는 아닌 듯

from math import sin, cos, radians
from sys import stdin
input = stdin.readline

def ccw(a, b, c):
    """두 벡터 ab, ac의 외적을 계산하는 함수"""
    return (c[1]-a[1]) * (b[0]-a[0]) > (b[1]-a[1]) * (c[0]-a[0])

def is_cross(p1_start, p1_end, p2_start, p2_end):
    """선분 p1과 p2가 교차하는지 판별하는 함수"""
    p1_side1 = ccw(p1_start, p2_start, p2_end)
    p1_side2 = ccw(p1_end, p2_start, p2_end)

    p2_side1 = ccw(p1_start, p1_end, p2_start)
    p2_side2 = ccw(p1_start, p1_end, p2_end)

    return (p1_side1 != p1_side2) and (p2_side1 != p2_side2)

def angle_to_unit_point(angle_x10):
    """
    선분 입력 정보를 단위 벡터 좌표로 변환하는 함수
    입력 데이터 : 각도 x 10 (변환 : 각도 -> 라디안 -> 단위 벡터 좌표)
    """
    rad = radians(angle_x10 * 0.1)
    return cos(rad), sin(rad)

def angle_dist_to_point(angle_x10, dist_x1000):
    """
    자원 입력 정보를 좌표로 변환하는 함수
    입력 데이터 : 각도 x 10, 거리 x 1000 (변환 : 각도 -> 라디안 -> 단위 벡터 좌표 * 거리) 
    """
    ux, uy = angle_to_unit_point(angle_x10)
    return ux * dist_x1000 / 1000, uy * dist_x1000 / 1000

N = int(input())

# 선분 시작점, 끝점 좌표 리스트 [ ( (x1, y1), (x2, y2), ) ]
lines = [] 

# 선분 정보 입력
for _ in range(N):
    uni1, uni2 = map(int, input().split())
    p1 = angle_to_unit_point(uni1)
    p2 = angle_to_unit_point(uni2)
    lines.append((p1, p2))

# p1, p2 좌표 계산
p1_uni, p1_dist = map(int, input().split())
p1_x, p1_y = angle_dist_to_point(p1_uni, p1_dist)

p2_uni, p2_dist = map(int, input().split())
p2_x, p2_y = angle_dist_to_point(p2_uni, p2_dist)

# 교차하는 선분 개수 계산
cross_count = 0
for (s, e) in lines:
    if is_cross( (p1_x, p1_y), (p2_x, p2_y), s, e ):
        cross_count += 1

# 짝수개 교차하면 "YES", 홀수개 교차하면 "NO"
if cross_count % 2 == 0:
    print("YES")
else:
    print("NO")
