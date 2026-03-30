x, y, w, s = map(int, input().split())

if(x > y):  # x를 y보다 작은 값으로 설정
    x, y = y, x

if(w > s): # 직선보다 대각선으로 가는 방법이 더 빠를 경우. 대각선으로 지그재그 형태로 이동
    distance = y * s
    if((y-x)%2 == 1): # 마지막 거리가 직선으로 한칸 거리일 경우.
        distance += w - s
elif(w * 2 > s): # 대각선으로 가로지르는 방법이 직선 두번보다 빠를 경우. 최대한 대각선으로 이동 후 남은 거리 직진
    distance = x * s + (y-x) * w
else: # 직선으로 이동하는 것이 빠를 경우. x + y의 거리만큼 직선으로 이동
    distance = (x + y) * w
print(distance)
