N = int(input())

num = list(map(int,input().split()))
lst= []

for i in range(N) :
    lst.insert(i-num[i],i+1)

for k in lst:
    print(k,end=' ')