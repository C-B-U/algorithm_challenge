from collections import deque, defaultdict

def bfs(N, start_v, graph):
    q = deque([start_v])
    result = []
    
    visited = [False] * (N + 1)  # 1-based 인덱싱
    visited[start_v] = True

    while q:
        cur_v = q.popleft()
        result.append(cur_v)

        for next_v in sorted(graph[cur_v]):  # 작은 번호부터 방문
            if not visited[next_v]:
                visited[next_v] = True
                q.append(next_v)
    
    return result

def dfs(N, cur_v, graph, visited, result):
    visited[cur_v] = True
    result.append(cur_v)

    for next_v in sorted(graph[cur_v]):  # 작은 번호부터 방문
        if not visited[next_v]:
            dfs(N, next_v, graph, visited, result)

N, M, V = map(int, input().split())

graph = defaultdict(list)  # defaultdict 사용

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

# DFS 실행
visited = [False] * (N + 1)
dfs_result = []
dfs(N, V, graph, visited, dfs_result)

# BFS 실행
bfs_result = bfs(N, V, graph)

# 결과 출력
print(" ".join(map(str, dfs_result)))
print(" ".join(map(str, bfs_result)))