import sys
from collections import deque
input = sys.stdin.readline

# case 1: [1] - [2], [2] - [3], [1] - [3]
#  [1]
#  / \
# [2][3]

# [1]을 큐에 넣고
# [1]을 큐에서 꺼내고 [1]과 연결된 [2], [3]을 찾는다. 
# 각각 방문 여부를 체크하고 안 했다면 큐에 추가.
# 2, 3번은 초기엔 당연히 방문 안 했을 거니까 비행 횟수 2번 추가.
# 이제 남은 건 [2, 3]인데 [2]를 꺼낸 시점에서 아까 비행 2번 하면서 [3]을 방문함. 즉 비행 횟수 추가 안 하고 패스
# [2] 꺼냈으니 [3]만 남는데 얘도 방문했으니 패스.

def bfs(startPoint):
    queue = deque([startPoint]) # [1]을 큐에 넣고
    visited[startPoint] = 1 # [1]을 방문했다고 기록하고
    
    cnt = 0 # 비행기 탄 횟수
    while queue:
        current_dest = queue.popleft() # [1]을 큐에서 꺼내고 
        for next_dest in graph[current_dest]: # [1]과 연결된 [2], [3]을 찾는다. 
            if not visited[next_dest]: # 각각 방문 여부를 체크하고 안 했다면..
                visited[next_dest] = 1 # 방문 도장을 찍고
                queue.append(next_dest) # 방문을 해야 하니까 큐에 넣기
                cnt += 1 # 방문 안한 곳을 방문했으니 비행 횟수 추가
    return cnt # while문 다 돌리고 나온 최종 횟수 적기

case = int(input()) # test case 수
for _ in range(case):
    n, m = map(int, input().split()) # 국가 수, 비행기 종류
    graph = [[] for _ in range(n + 1)] # 연결된 국가들 기록용
    visited = [0 for _ in range(n + 1)] # 방문했는가?
    
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b); graph[b].append(a) #예제 1 기준 다 돌면 [[], [2, 3], [1, 3], [2, 1]] 상태.
    print(bfs(1)) 

