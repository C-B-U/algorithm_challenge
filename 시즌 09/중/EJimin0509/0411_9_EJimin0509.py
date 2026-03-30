n = int(input())
if n==1 or n==2:
    print(0)
elif n==3:
    print(1)
else:
    start = 2
    d = 2
    cnt = 0
    for i in range(n-4):
        start += d
        cnt += 1
        if cnt == 2:
            cnt = 0
            d += 1
    print(start)