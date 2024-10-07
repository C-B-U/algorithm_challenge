# 역시 파이썬
from itertools import permutations
N, M = map(int, input().split())

for combination in permutations(range(1, N + 1), M):
    print(" ".join(map(str, combination)))