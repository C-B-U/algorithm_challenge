import sys
import math

n = int(sys.stdin.readline().rstrip())

class robot:
    def __init__(self, i, x, y, v):
        self.name = i
        self.x = x
        self.y = y
        self.v = v

        self.t = math.sqrt((x**2) + (y**2)) / self.v
    def __float__(self):
        return self.t

ans = []

current = robot(1, *list(map(int, sys.stdin.readline().rstrip().split())))
ans.append(current)

for i in range(1, n):
    current = robot(i+1, *list(map(int, sys.stdin.readline().rstrip().split())))
    ans.append(current)
   
ans.sort(key=float)
for r in ans:
    sys.stdout.write(f'{r.name}\n')

