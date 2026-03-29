# 흐즈로는 공을 좌우 수평 방향으로만 던질 수 있으므로, 각 과녁을 맞추기 위해 필요한 속도는 유일하다는 걸 금방 알 수 있다.

# 따라서 흐즈로가 각 과녁을 맞추는 데 필요한 속도를 계산한 후,
# 동일한 속도로 최대한 많은 과녁을 맞출 수 있는 경우를 찾으면 된다.

# 이 문제는 정확한 속도 값을 출력하는 게 아니라, 같은 속도로 맞출 수 있는 과녁의 최대 개수를 묻고 있으므로,
# 실제 속도를 수치적으로 계산하지 않고도 비율만을 이용해 해시값으로 처리할 수 있다. (실제 속도 계산은 실수 오차 등 고려해야할 게 많음)
# 해시 함수는 포물선 방정식을 적당히 수정하다보면 얻을 수 있으니 아무거나 사용하면 된다.

# 기하학은 역시 어려워..

from fractions import Fraction
from collections import defaultdict
from math import copysign
from sys import stdin
input = stdin.readline

def get_speed_hash(x, y, target_x, target_y):
    if target_y >= y: return None # 흐즈로보다 위에 있는 공은 맞출 수 없음
    speed = Fraction((target_x - x) ** 2, 2 * (y - target_y))
    speed *= copysign(1, target_x - x)
    return speed

# 해시맵을 사용해 같은 속도로 맞출 수 있는 과녁의 개수가 가장 많은 경우를 찾으면 된다.
x, y = map(int, input().split())
n = int(input())
targets = [ tuple(map(int, input().split())) for _ in range(n) ]
counts = defaultdict(int)
counts[None] = 0

for target in targets:
    speed = get_speed_hash(x, y, *target)
    if speed: counts[speed] += 1

print(max(counts.values()))