# 한 정점 v에 대해서 v가 최단 경로에 있기 위해서는
# (학교 -> v의 최단 거리) + (v -> 집의 최단거리) = (학교 -> 집의 최단거리)가 성립해야 한다.

# 학교에서 출발해 한 장소씩 이동한다고 할 때, k개의 장소를 지났을 때 다음으로 갈 수 있는 후보 정점이 하나만 존재한다면, 
# 최단 경로를 지나기 위해서는 그 정점을 무조건 지날 수밖에 없다.

# 그러나 매번 후보 정점이 2개 이상이라면, 각 단계마다 다른 선택지가 존재하므로
# 특정 정점 하나가 모든 최단 경로에 포함될 수 없고, 정답은 1이 된다.

from collections import deque
from sys import stdin
input = stdin.readline

def bfs(start, n, graph):
    dist = [ -1 ] * (n + 1)
    dist[start] = 0

    queue = deque([start])
    while queue:
        node = queue.popleft()

        for next in graph[node]:
            if dist[next] == -1:
                dist[next] = dist[node] + 1
                queue.append(next)

    return dist

N, M = map(int, input().split())
graph =  [[] for _ in range(N + 1) ]
for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

school_d = bfs(1, N, graph) # 학교에서 각 정점까지 거리
home_d = bfs(N, N, graph)   # 집에서 각 정점까지 거리
D = school_d[N]             # 학교 - 집 최단 거리

if D <= 1: print(1); quit()

# candis[k] = [ 정점을 k번 지났을 때 다음으로 건널 수 있는 후보 정점 정보, 후보 정점 번호 ]
#             [ None, None ]  - 계산하기 전
#             [ True, x ]     - 후보 정점 1개 발견, x는 후보 정점 번호
#             [ False, None ] - 후보 정점이 2개 이상임
candis = [ [None, None] for _ in range(D + 1) ]

for node in range(1, N + 1):
    if school_d[node] + home_d[node] == D:
        k = school_d[node]

        if candis[k][0] is None: 
            candis[k] = [ True, node ]
        else: 
            candis[k] = [ False, None ]

# 만약 정점을 k개 지났을 때 다음으로 갈 수 있는 정점이 유일한 경우가 있으면 해당 정점 출력 후 종료
# 후보 정점이 유일한 경우가 없으면 무조건 지나는 정점이 없으므로 1 출력
for k in range(1, D):
    status, node = candis[k]
    if status is True and 2 <= node <= N - 1:
        print(node)
        quit()

print(1)