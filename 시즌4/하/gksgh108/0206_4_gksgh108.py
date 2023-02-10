x,y,w,h = map(int,input().split())

print(min([x,y,w-x,h-y])) # 0,0에서 x,y랑 현재 위치인 x,y에서 w, h까지의 거리를 비교
