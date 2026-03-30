import sys
input = sys.stdin.readline

x, y, w, s = map(int, input().split())

only_straight = (x+y) * w

if (x+y) % 2 == 0:
    only_diagonal = max(x, y) * s
else:
    only_diagonal = (max(x, y) - 1) * s + w

straight_and_diagonal = (min(x, y) * s) + (abs(x-y) * w)

print(min(only_diagonal, only_straight, straight_and_diagonal))