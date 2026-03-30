import sys
input =sys.stdin.readline

n,p,k,d=map(int,input().split())
answer=[0]*(n)
if d==1:
    if p<k:
        answer="Wrong information"
    else:
        if n==k:
            if p%k==0:
                for i in range(n):
                    answer[i]=int(p/k)
            else:
                answer="Wrong information"
        else:
            if p%k==0:
                for i in range(k):
                    answer[i]=int(p/k)
            else:
                t=p%k
                if int(t/(n-k))<int(p/k):
                    for i in range(k):
                        answer[i]=int(p/k)
                    index=k
                    while t>0:
                        answer[index]+=1
                        t-=1
                else:
                    answer="Wrong information"
else:
    l=d-1
    ind=0
    summ=0
    while l>0:
        answer[ind]+=l
        summ+=l
        ind+=1
        l-=1
    p-=summ
    if p>=0:
        answer[0]+=p
    else:
        answer="Wrong information"
whsskdjfuqsp=[]    
if answer!="Wrong information":
    for i in range(k):
        if answer[i] not in whsskdjfuqsp:
            whsskdjfuqsp.append(answer[i])
    if len(whsskdjfuqsp)!=d:
        answer="Wrong information"
if answer=="Wrong information":
    print(answer)
else:
    for i in range(n):
        print(answer[i])