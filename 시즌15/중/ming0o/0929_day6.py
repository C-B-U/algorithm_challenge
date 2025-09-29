import sys
from collections import deque
N = int(sys.stdin.readline())
graph = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
max_rain = max(map(max, graph))
# 물의 양 조절하기
# 물에 잠기는 영역 확인하기
# 안전한영역의 개수 체크하기
dx = [0,0,-1,1]
dy = [1,-1,0,0]
def bfs(i,j):
    global count
    q = deque()
    q.append((i,j))
    sink[i][j] = True
    count += 1 # 안전한 영역 개수 1 추가
    while q:
        x,y = q.popleft()
        for i in range(4):
            nx = x + dx[i] # 상하좌우 확인
            ny = y + dy[i]
            if nx<0 or ny < 0 or nx >= N or ny >= N: # 영역 밖으로 나가면 x
                continue
            if sink[nx][ny]==False: # 상하좌우중 잠겨있지 않은 부분이 있다면
                sink[nx][ny] = True # 잠겼다고 가정시킴
                q.append((nx,ny))
count_list = []
for rain in range(max_rain): # 물의 양 조절
    count = 0 # 안전한 영역의 개수 카운트
    sink = [[False for _ in range(N)] for i in range(N)] # 물에 잠긴 부분 초기화
    for i in range(N):
        for j in range(N):
            if graph[i][j]<=rain:
                sink[i][j]=True # 물에 잠기는 영역 확인하기
    for i in range(N):
        for j in range(N):
            if sink[i][j]==False: # 잠기지 않은 영역일 경우에만
                bfs(i,j) # bfs실행하여 영역모두 잠겼다고 가정하면서 안전한 영역 1 추가시키기
    count_list.append(count) # count_list에 추가 

print(max(count_list)) # count_list중에서 최대값을 출력