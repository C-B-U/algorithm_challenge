# 2605 : 줄 세우기

import sys
input = sys.stdin.readline

n = int(input())
seq = list(map(int, input().rstrip().split()))

idx = [1]
for i in range(1, n):
    idx.insert(i - seq[i], i + 1)

for i in idx:
    print(i, end = ' ')