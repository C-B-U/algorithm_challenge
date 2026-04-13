# x번 이동했을 때 돌돌이와 토카가 이동한 거리를 계산하는 함수를 만든다.
# 해당 함수를 기준으로 이분탐색을 진행해 돌돌이가 토카가 몇 번 째에 집에 도달하는지 계산한다.
# 도달 시점이 토카카 돌돌이보다 빠른 경우에만 토카는 잡히지 않을 수 있다.

from bisect import bisect_left

A, B = map(int, input().split())
C, D = map(int, input().split())
K = int(input())

class Runner:
    def __init__(self, speed, accel):
        self.speed = speed
        self.accel = accel

    def __len__(self):
        return 10 ** 16

    def __getitem__(self, x):
        # x번 이동했을 때 이동 거리 = 등차수열의 합 (첫째항 0)
        # 부동소수점 오차 방지를 위해 / 2 는 생략

        # x번 이동했을 때 속도가 음수라면, 이분 탐색시 고려하지 않기 위해 무한대 반환
        if (self.speed + self.accel * (x - 1)) < 0:
            return float('inf')

        return x * (2 * self.speed + (x - 1) * self.accel)

toca = Runner(B, -K)
doldol = Runner(D, 0)

toca_c = bisect_left(toca, A * 2) # 토카가 집까지 이동하는데 걸리는 이동 횟수
doldol_c = bisect_left(doldol, (A + C) * 2) # 돌돌이가 집까지 이동하는데 걸리는 이동 횟수

if toca[toca_c] == float('inf'):
    print(-1)
else:
    print(toca_c if toca_c < doldol_c else -1)