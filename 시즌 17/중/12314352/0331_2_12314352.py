Trip = int(input())

for i in range(Trip):
    a, b = map(int, input().split())
    
    for i in range(b):
        input()  # 간선은 읽기만 하고 무시
    
    print(a - 1)
