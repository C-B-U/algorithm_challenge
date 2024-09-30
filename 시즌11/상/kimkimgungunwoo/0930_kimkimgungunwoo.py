import sys

input=sys.stdin.readline

N,M=map(int,input().split())

answer=0

def search_field(t1,t2):
    dp=[[0]*N for x in range(N)]
    
    for i in range(N):
        for j in range(N):
            if field[i][j]==t1 or field[i][j]==t2:
                dp[i][j]=1
    
    
    for i in range(1,N):
        for j in range(1,N):
            if dp[i][j]!=0:
                dp[i][j]=min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])+1
    
    return max(map(max,dp))
                


field=[[0]*N for x in range(N)]

for i in range(M):
    x,y,l,f=map(int,input().split())
    for i in range(y,y+l):
        for j in range(x,x+l):
            field[i][j]=f
            

for i in range(1,8):
    for j in range(i+1,8):
        answer=max(answer,search_field(i,j))
        
print(answer**2)