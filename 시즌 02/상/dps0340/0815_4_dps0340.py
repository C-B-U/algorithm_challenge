N = int(input())

NOT_VISITED = 99999999
graph = [[] for j in range(N)]

for i in range(N):
    lst = list(map(int, input().split()))
    node = lst[0]
    node -= 1
    idx = 1
    while lst[idx] != -1:
        another_node, cost = lst[idx], lst[idx+1]
        another_node -= 1
        graph[node].append((another_node, cost))
        graph[another_node].append((node, cost))
        idx += 2

result = -1
costs = [0 for x in range(N)]


def dfs(visited, idx, cost):
    global result
    result = max(result, cost)
    costs[idx] = cost
    visited[idx] = True
    for (i, c) in graph[idx]:
        if not visited[i]:
            dfs(visited, i, cost + c)


dfs([False for x in range(N)], 0, 0)

result = -1

argmax = -1
max_val = -1
for i in range(N):
    if max_val < costs[i]:
        argmax = i
        max_val = costs[i]

dfs([False for x in range(N)], argmax, 0)

print(result)
