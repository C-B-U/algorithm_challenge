N=int(input())
inp=list(map(int,input().split()))
dp=[0]*(N+1)
for i in range(N):
    dp[inp[i]]=dp[inp[i]-1]+1
print(N-max(dp))