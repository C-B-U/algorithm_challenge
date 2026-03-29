x, y, w, s = map(int, input().split())

#평행으로만 이동
min1 = (x+y) * w

#대각선으로만 이동
if (x + y) % 2 == 0:
    min2 = max(x, y) * s
#대각선이동 + 평행이동 1번
else:
    min2 = (max(x, y) - 1) * s + w

#평행이동 + 대각선이동
m3 = (min(x, y) * s) + (abs(x-y) * w)

print(min(min1, min2, m3))