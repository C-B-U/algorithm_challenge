import sys

input = sys.stdin.readline

s = set()
n = int(input())
a, b = map(int, input().split())
for i in range(n):
    x, y = map(int, input().split())
    s.add((x, y))

ans = 0
for v in s:
    if (v[0]+a, v[1]+b) in s and (v[0], v[1]+b) in s and (v[0]+a, v[1]) in s:
        ans += 1

print(ans)
