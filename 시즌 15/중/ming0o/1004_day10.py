import sys
input = sys.stdin.readline

def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    a = find(a)
    b = find(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

for i in range(int(input().rstrip())):
    n, k = int(input().rstrip()), int(input().rstrip())
    parent = [i for i in range(n)]
    for _ in range(k):
        a, b = list(map(int, input().rstrip().split()))
        if find(a) != find(b): union(a, b)
    print(f'Scenario {i + 1}:')
    for _ in range(int(input().rstrip())):
        a, b = list(map(int, input().rstrip().split()))
        if find(a) == find(b):
            print(1)
        else:
            print(0)
    print()

좋아요공감
공유하기게시글 관리
