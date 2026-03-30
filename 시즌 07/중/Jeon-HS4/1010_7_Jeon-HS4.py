T = int(input())
for i in range(T):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    k = pow((x1-x2)**2 + (y1-y2)**2, 0.5)
    d = r1 + r2
    if(r1 > r2):
        if(k+r2 < r1):
            print("0")
            continue
        elif(k+r2==r1):
            print("1")
            continue
    if(r1 < r2):
        if(k+r1 < r2):
            print("0")
            continue
        elif(k+r1==r2):
            print("1")
            continue
    if k==0:
        if(r1== r2):
            print("-1")
            continue
    if k > d:
        print("0")
    elif k == d:
        print("1")
    elif k < d:
        print("2")
