import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

N, M = map(int,input().split())

parent = [0] * (N+1)
for i in range(N+1):
    parent[i] = i

def find(a):
    if a == parent[a]:
        return a
    p = find(parent[a])
    parent[a] = p
    return parent[a]

def union(a,b):
    a = find(a)
    b = find(b)

    if a == b:
        return
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

for _ in range(M):
    o, a, b = map(int,input().split())
    if o == 0:
        union(a,b)
    elif o == 1:
        if find(a) == find(b):
            print('YES')
        else:
            print('NO')