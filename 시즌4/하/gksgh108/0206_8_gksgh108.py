x, y = map(int, input().split())
N= int(input())
result = 200
rx, ry = 0, 0

for i in range(N):
    a, b = map(int, input().split())
    dis = pow(pow((x-a),2) + pow((y-b),2), 1/2) # 거리 계산
    if (dis<result):
        result = dis
        rx, ry = a, b

print(rx, ry)
