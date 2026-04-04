N, M = map(int, input().split())
A = list(map(int, input().split()))

if sum(A) - N >= M:
    print("DIMI")
else:
    print("OUT")
