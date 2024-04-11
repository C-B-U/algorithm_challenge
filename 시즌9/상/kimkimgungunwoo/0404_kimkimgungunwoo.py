'''
다익스트라 라는게 있었구나

최단 거리로 지나갔던 엣지들을 알아내서 거기를 막으면 되긴 할듯

'''
from collections import deque
import heapq
import sys

N,M=map(int,sys.stdin.readline().split())
Inf=sys.maxsize
field=[[] for x in range(N+1)] #쉬운표기를 위해 0 비워둠 
route=[0]*(N+1) #도둑이 지나갈 루트 저장하고 하나하나 막아보기 위해
for i in range(M): #그래프생성
    a,b,c=map(int,sys.stdin.readline().split())
    field[a].append((b,c))
    field[b].append((a,c))

def dijkstra(s1,s2):  #막은 길의 양쪽 노드 s1,s2
    distance=[Inf]*(N+1)
    distance[1]=0    
    queue=[]
    heapq.heappush(queue,(0,1)) #시작노드의 거리,노드번호 넣음
    while queue:
        dist,now=heapq.heappop(queue)
        
        if distance[now]<dist: #만약 이미 최단거리가 갱신되어 있을경우 무시
            continue
        
        for i in field[now]: #인접노드 순회
            weight=dist+i[1] #큐에 저장되어있던 지금까지의 거리+다음에 갈 노드와의 거리
            
            if s1==now and s2==i[0] or s1==[0] and s2==now: #검문중인 도로를 건너야 하는 경우는 무시
                continue
            if weight<distance[i[0]]: #현재 노드를 통해 도달하는 것이 더 짧을경우 
                distance[i[0]]=weight
                route[i[0]]=now #도둑의 루트 저장
                heapq.heappush(queue,(weight,i[0]))
    return distance
T=dijkstra(0,0) #통행 제한 없이 최소비용가는 방법
answer=-1 #불가능한 상황을 위한 
K=N #그동안 도둑이 기나간 루트를 역으로 도출

while not K ==1:
    s=route[K]
    dis=dijkstra(s,K)
    if dis[N]==Inf: #만약 도달할수 없는 곳일경우 -1출력하도록
        print(-1)
        exit()
    answer=max(answer,dis[N]-T[N]) #검문 피해서 간 시간-검문없이 간 시간 비교
    K=s #지나온 루트 거꾸로 가기
print(answer)