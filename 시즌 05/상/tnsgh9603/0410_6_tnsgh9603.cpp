import sys
from collections import deque

N = int(sys.stdin.readline())
for _ in range(N):
    s = sys.stdin.readline().rstrip()
    n = int(sys.stdin.readline())
    dq = deque(sys.stdin.readline().lstrip('[').rstrip(']\n').split(','))
    cnt, flag = 0, 0
    for i in s:
        if i == 'R':
            cnt += 1
        else:
            if n > 0:
                if cnt % 2:
                    dq.pop()
                    n -= 1
                else:
                    dq.popleft()
                    n -= 1
            else:
                flag = 1
                break
    if flag:
        print("error")
        continue
    if cnt % 2:
        dq.reverse()
    print("[", end="")
    print(*dq, sep=",",end="")
    print("]")
