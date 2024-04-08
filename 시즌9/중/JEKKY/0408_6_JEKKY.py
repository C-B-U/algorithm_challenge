P = int(input())
for i in range(P):
    N,M = map(int, input().split())
    cnt = 0
    a=b=1
    while(True):
        tmp = (a+b)%M
        a=b
        b=tmp
        cnt+=1
        if a==1 and b==1:break
    print(N, cnt)