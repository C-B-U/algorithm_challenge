from heapq import heappush, heappop
from sys import stdin
input = stdin.readline

N = int(input())
problems = []

for _ in range(N):
    deadline, reward = map(int, input().split())
    problems.append((deadline, reward))

# 데드라인 오름차순, 보상 내림차순 정렬
problems.sort(key=lambda x: (x[0], -x[1]))

chosen = []  # 지금까지 선택한 문제들의 보상 (힙)

for deadline, reward in problems:
    heappush(chosen, reward)

    # 선택한 문제 수가 데드라인을 초과하면,
    # 가장 보상이 작은 문제를 버려서 보상을 최대화
    if len(chosen) > deadline:
        heappop(chosen)

print(sum(chosen))