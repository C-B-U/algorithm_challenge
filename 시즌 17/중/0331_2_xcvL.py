Nlist = []
T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    for _ in range(M):
        input()
    Nlist.append(N - 1)
for n in Nlist:
    print(n)