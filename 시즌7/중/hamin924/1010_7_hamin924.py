#원의 방정식 문제

import sys
import math

read = lambda: sys.stdin.readline().rstrip()

T = int(read())

for _ in range(T):
    x1, y1, r1, x2, y2, r2 = map(int, read().split())
    distance = math.sqrt((x1-x2)**2 + (y1-y2)**2)  
    if distance == 0 and r1 == r2:
        print(-1)
    elif abs(r1-r2) == distance or r1 + r2 == distance:
        print(1)
    elif abs(r1-r2) < distance < (r1 + r2):
        print(2)
    else:
        print(0)