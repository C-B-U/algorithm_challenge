# 블랙잭
from itertools import combinations

n, m = map(int, input().split())

a = list(map(int,input().split()))
result = []

for i in combinations(a, 3):
    if sum(i) > m:
        continue
    else:
        result.append(sum(i))

print(max(result))
    