import sys
input = sys.stdin.readline

Q = int(input())

# 처음 배열은 1, 2, 3, 4, ... 이므로 min = 1 step = 1
current_min = 1
step = 1

for _ in range(Q):
    query = input().split()
    op = int(query[0])
    
    if op == 0:
        x = int(query[1])
        # 모든 원소에 x를 더하면 최솟값은 x만큼 커짐. 근데 스텝은 그대로.
        current_min += x
        
    elif op == 1:
        x = int(query[1])
        # 모든 원소에 x를 곱하면 최솟값도 x배가 되고, 스텝도 x배가 됨.
        current_min *= x
        step *= x
        
    elif op == 2:
        n = int(query[1])
        # 가장 작은 원소부터 n개를 지우면, 새로운 최솟값은 기존 최솟값에서 (step * n)만큼 더해진 값이 됨.
        current_min += step * n
        
    elif op == 3:
        # 최솟값
        print(current_min)
