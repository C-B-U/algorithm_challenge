a = list(map(int,input().split()))
if a[0] >= a[1]:
    print(0)

else:
    b = 1
    for i in range(1, a[0]+1):
        b = (b*i)%a[1]
    print(b)

