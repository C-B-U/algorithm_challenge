# 1번 집의 색은 2번 집의 색과 같지 않아야 한다.
# 3번 집의 색은 2번 집의 색과 같지 않아야 한다.
# i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
import sys
input = sys.stdin.readline

n = int(input())
RGB = []
for i in range(n):
    RGB.append(list(map(int, input().split())))

for i in range(1, n):
    RGB[i][0] = RGB[i][0] + min(RGB[i-1][1], RGB[i-1][2])
    RGB[i][1] = RGB[i][1] + min(RGB[i-1][0], RGB[i-1][2])
    RGB[i][2] = RGB[i][2] + min(RGB[i-1][0], RGB[i-1][1])

print(min(RGB[n-1]))