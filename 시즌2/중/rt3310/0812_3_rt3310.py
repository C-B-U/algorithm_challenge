from collections import deque

n, m, r = list(map(int, input().split()))

table = [[] for _ in range(n+1)]
visited = [0] * (n+1)

for i in range(m):
    u, v = list(map(int, input().split()))
    table[u].append(v)
    table[v].append(u)

def bfs(cur, order):
    q = deque([cur])
    visited[cur] = order
    order += 1
    
    while q:
        elem = q.popleft()
        table[elem].sort(reverse=True)
        for i in table[elem]:
            if not visited[i]:
                q.append(i)
                visited[i] = order
                order += 1
            
bfs(r, 1)

for i in visited[1:]:
    print(i)