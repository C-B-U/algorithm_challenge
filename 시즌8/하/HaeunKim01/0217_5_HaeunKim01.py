
# input 대신 sys 라이브러리로 시간 줄임

import sys
n = int(sys.stdin.readline())
list = []
for i in range(n):
    a, b = map(int, sys.stdin.readline().split())
    list.append([a, b])
list.sort()
for i in list:
    print(i[0], i[1])