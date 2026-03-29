n = int(input())
graph = []

# 간선에 대한 정보 저장
for _ in range(n):
    graph.append(list(map(int, input().split())))
visited = [0 for _ in range(n)]

# dfs 방법을 사용해서 출발 노드에서 방문한 다른 노드의 정보를 저장
def dfs(x):
    for i in range(n):
        if graph[x][i] == 1 and visited[i] == 0:
            visited[i] = 1
            dfs(i)

# 각 노드마다 출발하는 dfs 알고리즘을 적용해서 결과물 출력
for i in range(n):
    visited = [0 for _ in range(n)]
    dfs(i)
    for j in range(n):
        print(visited[j], end=' ')
    print()
