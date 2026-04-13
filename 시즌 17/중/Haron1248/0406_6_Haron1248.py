import sys

input = sys.stdin.readline
n = 1
d = 1
k = 0
for _ in range(int(input())):
    line = list(map(int, input().split()))
    if len(line) == 1:
        print(d * n + k)
        continue
    order, m = line
    if order == 0:
        k += m
    elif order == 1:
        d *= m
        k *= m
    else:
        n += m
