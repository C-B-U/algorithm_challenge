import sys

input = sys.stdin.readline

ans = 0
b = 0
for n in range(int(input())):
    d, v = map(int, input().split())
    ans += max(0, v - b)
    if v - b < 0:
        b = d - (v - b)
    else:
        b = d

print(ans)
