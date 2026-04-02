N, M = map(int, input().split())
A = list(map(int, input().split()))

total = sum(a - 1 for a in A)

if total >= M:
    print("DIMI")
else:
    print("OUT")
