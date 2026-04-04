import sys

input = sys.stdin.readline

N, M = map(int, input().split())
A = list(map(int, input().split()))

safe_time = sum(a - 1 for a in A)

if safe_time >= M:
    print("DIMI")
else:
    print("OUT")
