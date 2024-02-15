A, B, C = map(int, input().split())

if B >= C:
    print(-1)
else:
    x = 0
    while True:
        if A + B * x < C * x:
            print(x)
            break
        x += 1

        