# 2167번: 2차원 배열의 합

import sys  # input 보다 sys.stdin.readline()이 여러줄 입력받기에는 좋기 때문에 import를 시켜줌

N,M = map(int, sys.stdin.readline().split())
numbers = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]  # 2차원 리스트에 숫자들을 입력함

for a in range(int(input())):
    i,j,x,y = map(int, sys.stdin.readline().split())
    sum = 0
    for b in range(i-1,x):  # i,j,x,y의 값은 리스트에서 0,0부터가 아니라 1,1부터 입력되기 때문에 -1을 해줌.
        for c in range(j-1,y):
            sum += numbers[b][c]  # 그 사이의 수를 반복하며 더함
    print(sum)
    
# 백준 기준 Pypy3 3464ms, Python3 시간초과
# 반복 연산을 줄이는 방향으로 수정해야 
