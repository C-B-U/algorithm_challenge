import sys
input = sys.stdin.readline
from collections import deque

que = deque([])


while True:
    num = int(input())
    if num == 0 :
        break
    else:
        que.append(num)

for i in que:
    res = [i]
    while True:
        i *= i
        i = str(i)
        i = i.zfill(8)
        i = i[4//2:2*4-4//2]
        i = int(i)  # 문자열 → 정수

        if i not in res:
            res.append(i)
        else:
            print(len(res))
            break
