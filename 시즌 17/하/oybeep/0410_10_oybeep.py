n, m = map(int, input().split())

edges = []

for i in range(n - m):
    edges.append((i, i+1))

for i in range(n - m + 1, n):
    edges.append((n - m, i))

for u, v in edges:
    print(u, v)
