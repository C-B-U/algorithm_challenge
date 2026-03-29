# 전체에서 최고 높이 H를 먼저 얻고, 이후에는 간격 2, 4, 8, ... 로 탐지기를
# 한 번씩만 사용해 매 단계마다 후보를 절반으로 줄인다.

# [ 과정 ]
# 1. 1 ~ N 을 모두 확인해 최고 높이를 구한다.
# 2. 간격 2 탐지기를 이용해 홀수번들을 확인한다. -> 최고 높이보다 낮으면 목표는 짝수번에 있다.
# 3. 간격 4 탐지기를 이용해 다시 후보들을 절반으로 줄인다.
# 4. 이 과정을 반복하면 최종 후보를 구할 수 있다.

from builtins import print as oprint
from sys import stdin, stdout
input = stdin.readline

def print(*args, **kwargs):
    oprint(*args, **kwargs)
    stdout.flush()

def query(s, a, b):
    print(f"? {s} {a} {b}")
    return int(input())

N = int(input())
H = query(1, 1, N)

target = 0
gap = 1

while True:
    step = gap * 2 # 탐색 간격
    if step > N: break # 간격이 N을 넘으면 종료

    # 계속 같은 위치에서 시작하면 중복 탐지 횟수가 많아져
    # 배터리가 낭비되므로 위치 조정
    start = target + gap + 1 # 시작 위치
    
    if start <= N:
        count = (N - start) // step + 1  # 탐색 개수 (탐색 범위가 N을 넘지 않도록)
        q_max = query(start, step, count)
        if q_max == H:
            target += gap

    gap *= 2 

# 간격이 N을 넘어서 종료되면 최대 2개 후보가 남을 수 있음
# (target + 1) 또는 (target + gap + 1)
answer = target + 1
second = target + gap + 1
if second <= N:
    # 아직 쓰지 않은 탐지기로 정답 확인 (배터리 1 소모)
    if query(answer, N, 1) < H:
        answer = second

print(f"! {answer}")