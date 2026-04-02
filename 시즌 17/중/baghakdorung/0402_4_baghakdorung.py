import sys
from bisect import bisect_left

input = sys.stdin.readline

n, m = map(int, input().split())

titles = []
limits = []

for _ in range(n):
    title, limit = input().split()
    limit = int(limit)

    if not limits or limits[-1] != limit:
        titles.append(title)
        limits.append(limit)

for _ in range(m):
    score = int(input())
    idx = bisect_left(limits, score)
    print(titles[idx])