
n, m, r = list(map(int, input().split()))

table = [[] for _ in range(n+1)]
visited = [0] * (n+1)

for i in range(m):
    u, v = list(map(int, input().split()))
    table[u].append(v)
    table[v].append(u)

for i in table:
    i.sort()

def dfs(cur, order):
    stack = [cur]
    while stack:
        elem = stack.pop()
        if not visited[elem]:
            visited[elem] = order
            order += 1
        for i in table[elem]:
            if not visited[i]:
                stack.append(i)
                
dfs(r, 1)

for i in visited[1:]:
    print(i)