import math
W, H, N = map(int, input("사각형의 가로, 세로, N : ").split())

#결과변수 초기화
result = 0

# for i in range(1, N):
#     x1 = W * (i / N)
#     y1 = H * (i / N)
#     x2 = W * ((N - i) / N)
#     y2 = H * ((N - i) / N)
#     length = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
#     result += length

if (N%2 == 0):
    result = (N-2) / 4
else:
    result = (N-1)*(N-1)/(4*N)

result += 2*H

print(round(result, 6))