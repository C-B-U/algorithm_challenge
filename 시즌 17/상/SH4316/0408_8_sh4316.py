n = int(input())
a = [-1]
a.extend((map(int, input().split(" "))))
a.append(-1)
b = [-1]
b.extend((map(int, input().split(" "))))
b.append(-1)

# print(len(a), len(b))

MAX = float('inf')
cost = [MAX for i in range(n+2)]
graph = [[] for i in range(n+2)]
cost[n+1] = 0
cost[0] = 0

for i in range(1, n+1):
    # print(i, min(i + a[i], n+1))
    # print(i, max(i - a[i], 0))
    graph[min(i + a[i], n+1)].append(i)
    graph[max(i - a[i], 0)].append(i)

# print(graph)

from collections import deque

stack = deque()
stack.append(n+1)

while len(stack) != 0:
    ind = stack.popleft()
    for node in graph[ind]:
        v = b[node] + cost[ind]
        if cost[node] > v:
            cost[node] = v
            stack.append(node)
            # print(node, ind, v)

# print(cost)

stack = deque()
stack.append(0)

while len(stack) != 0:
    ind = stack.popleft()
    for node in graph[ind]:
        v = b[node] + cost[ind]
        if cost[node] > v:
            cost[node] = v
            stack.append(node)

for i in range(1, n+1):
    print(cost[i], end=" ")
