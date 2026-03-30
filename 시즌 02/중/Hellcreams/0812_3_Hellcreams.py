from sys import stdin
from collections import deque

n, m, r = map(int, stdin.readline().split(' '))
visit = [0 for _ in range(n+1)]
seq = 0
routes = {}
for i in range(n+1):
    routes[i] = []

for _ in range(m):
    route = tuple(map(int, stdin.readline().split(" ")))
    routes[route[0]].append(route[1])
    routes[route[1]].append(route[0])

for i in range(n):
    routes[i].sort(reverse=True)


def reach(x):
    if not visit[x]:
        global seq
        seq += 1
        visit[x] = seq
        return True
    return False


current_loc = deque([r])
reach(r)
while len(current_loc):
    point = current_loc.popleft()
    for i in routes[point]:
        if reach(i):
            current_loc.append(i)

for i in visit[1:]:
    print(i)

# 96% 틀렸습니다
