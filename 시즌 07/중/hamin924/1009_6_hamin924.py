import sys
sys.setrecursionlimit(10000) # 런타임 오류 방지

def dfs(x, y):
    dx = [0,0,-1,1]
    dy = [1,-1,0,0]

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if (0 <= nx < M) and (0 <= ny < N):  # nx:ny ↔ M:N 범위 참고
            if graph[ny][nx] == 1:
                graph[ny][nx] = -1  # 배추가 인접할 때 체커
                dfs(nx, ny)
                  
T = int(input())

for i in range(T):
    M, N, K = map(int, input().split())  # M:가로, N:세로, K:개수
    graph = [[0]*M for i in range(N)]
    cnt = 0

    for j in range(K):
        X, Y = map(int, input().split())
        graph[Y][X] = 1
      
    # dfs 활용해서 배추 그룹 수 세기
    for x in range(M):
        for y in range(N):
            if graph[y][x] == 1:
                dfs(x, y)
                cnt += 1

    print(cnt)