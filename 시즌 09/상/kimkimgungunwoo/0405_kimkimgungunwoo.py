import sys
input=sys.stdin.readline
index=answer=0
N=int(input())
lst=[]
for i in range(N):
    h=int(input())
    ind=i
    while lst:
        if lst[-1][0]>h:
            s=lst.pop()
            answer=max(answer,s[0]*(i-s[1]))
            ind=s[1]
        elif lst[-1][0]==h:
            s=lst.pop()
            ind=s[1]
        elif lst[-1][0]<h:
            break
    
    lst.append((h,ind))
while lst:
    s=lst.pop()
    answer=max(answer,s[0]*(N-s[1]))
print(answer)  