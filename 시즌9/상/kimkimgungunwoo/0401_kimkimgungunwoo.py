import sys
input=sys.stdin.readline
m,n=map(int,input().split())
field=[[0 for x in range(n+1)] for z in range(m+1)]


for i in range(1,m+1):
    inp=input()
    for j in range(1,n+1):
        if inp[j-1]=="1":
            field[i][j]=min(field[i-1][j-1],field[i][j-1],field[i-1][j])+1
        if inp[j-1]=="0":
            field[i][j]=0
answer=0
for i in range(1,m+1):
    for j in range(1,n+1):
        answer=max(field[i][j],answer)
print(answer**2)
            
