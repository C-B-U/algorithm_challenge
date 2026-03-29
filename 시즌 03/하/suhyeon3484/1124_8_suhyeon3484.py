# 2702 : 초 6 수학

t = int(input())

for _ in range(t):
    a, b = map(int, input().split())

    min_val = min(a, b)
    for i in range(min_val + 1, -1, -1):
        if a % i == 0 and b % i == 0:
            print(a * b // i, i, end = ' ')
            print()
            break