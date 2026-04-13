N,M=map(int, input().split())

if N>=M: print(0)

else:
    remainder=1
    for i in range(1,N+1): remainder=(remainder*i)%M
    print(remainder)