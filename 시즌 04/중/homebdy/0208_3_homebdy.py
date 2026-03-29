n, l = map(int, input().split())

for i in range(l, 101):
    x = n / i - (i-1) / 2
    if int(x) == x:
        x = int(x)
        if x > -1:
            for i in range(x, x+i):
                print(i, end=" ")
            break
else:
    print(-1)