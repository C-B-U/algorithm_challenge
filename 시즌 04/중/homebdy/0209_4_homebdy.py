from collections import deque

n, k = map(int,input().split())
visited = [-1 for _ in range(100001)]

q = deque()
q.append(n)
visited[n] = 0

while q:
    x = q.popleft()
    if x == k:
        print(visited[x])
        break
    for nextP in (x-1, x+1 ,2*x):
        if 0 <= nextP <= 100000 and visited[nextP] == -1 :
            visited[nextP] = visited[x] + 1
            q.append(nextP)