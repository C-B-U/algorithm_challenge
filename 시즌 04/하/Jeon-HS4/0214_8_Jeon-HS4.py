# 13221번: Manhattan

x,y = map(int, input().split()) #처음 손님의 위치를 입력
N = int(input())

d = 201  # 그리드의 최대 거리는 200이므로 그 이상으로 설정
dx, dy = 0, 0  # 택시의 기본 위치는 임의의 값으로 설정

for _ in range(N):
    tx, ty = map(int, input().split())
    td = abs(x-tx) + abs(y-ty)  #x축으로의 거리와 y축으로의 거리의 합을 구함
    if(td<d):  # 가장 가까이 있는 택시일 경우 그 거리와 좌표를 저장
      d,dx,dy = td,tx,ty      

print(dx,dy)
