#1085번: 직사각형에서 탈출

x,y,w,h = map(int,input().split())

# 경계선까지 가장 짧은 거리는 현재 좌표로부터 모서리까지의 직선 거리이므로
# x,y,w-x,h-y의 최솟값만큼 이동하면 된다.
print(min([x,y,w-x,h-y]))
