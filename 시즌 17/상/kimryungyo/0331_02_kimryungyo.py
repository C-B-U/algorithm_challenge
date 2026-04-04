# [ 풀이 ]
# 문제에서 주어진 조건대로 x일 시점에서 밀키트를 먹을 수 있는지 없는지 판단하는 함수를 만든다.
# 해당 함수를 기준으로 이분 탐색을 진행한다.

from sys import stdin
from heapq import heappush, heappop
from bisect import bisect_left
input = stdin.readline

N, G, K = map(int, input().split())  # 재료 수, 세균 상한, 뺄 수 있는 재료 수

class IngredientsList:
    def __init__(self, n):
        self.n = n
        self.ing_list = []

    def __len__(self):
        return 10 ** 10

    def __getitem__(self, day):
        t_spoil = 0 # 총 세균 수
        unimp_heap = []

        for [spoil, life, unimp] in self.ing_list:

            i_spoil = spoil * ( day - life if day - life > 1 else 1 )
            t_spoil += i_spoil

            # 안 중요한 재료면 힙에 추가 (최대 K개)
            if unimp:
                heappush(unimp_heap, i_spoil)
                if len(unimp_heap) > K:
                    heappop(unimp_heap)

        # 뺄 수 있는 재료 빼기
        while unimp_heap:
            t_spoil -= heappop(unimp_heap)

        return t_spoil > G

il = IngredientsList(N)
for _ in range(N):
    il.ing_list.append(tuple(map(int, input().split())))

result = bisect_left(il, True) - 1
print(result)