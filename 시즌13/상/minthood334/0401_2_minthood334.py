import sys
from math import gcd # 최대공약수 구하는 함수
from collections import Counter # 겹치는 횟수 구하는 dictionary

input = sys.stdin.readline

x0, y0 = map(int, input().split())
n = int(input())

counter = Counter()

for _ in range(n):
    x, y = map(int, input().split())
    dx = x - x0
    dy = y - y0

    #y축으로는 힘을 못 주니까, y값이 y0 값보다 크면 연산에서 제외
    if dy >= 0 or dx == 0:
        continue

    '''
    포물선 방정식을 정리하면 x^2 / -2y = vx^2 /g 이다.
    x^2 / -2y 의 비율과 방향이 똑같으면 같은 속도를 가진다 볼 수 있다.
    같은 속도를 가진다 === 과녁에 도달할 수 있다.
    '''

    nt = dx * dx #분자
    dt = -2 * dy #분모

    g_val = gcd(nt, dt) # 두 수의 최대공약수
    #기약분수 형태로 변환
    nt //= g_val
    dt //= g_val
    direction = 1 if dx > 0 else -1 #방향
    counter[(nt, dt, direction)] += 1 #분자, 분모, 방향 형태로 저장함

print(max(counter.values(), default=0))
