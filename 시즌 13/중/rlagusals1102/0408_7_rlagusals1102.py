from itertools import combinations

n, m, k = map(int, input().split())

c = [set(i) for i in combinations(range(1, n + 1), m)]
total = len(c)

win = sum(
    1 for i in c for j in c if len(i & j) >= k
)

print(win / (total * total))
