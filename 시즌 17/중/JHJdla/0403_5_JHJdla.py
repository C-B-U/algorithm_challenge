import sys


H, N = map(int, input().split())

a = []
save1 = [0] * N

for i in range(N):
    b = list(map(int, input().split()))
    a.append([b[1], i])

a.sort()

for i in range(N):
    save1[a[i][1]] = i + 1

print("YES")
print(*save1)