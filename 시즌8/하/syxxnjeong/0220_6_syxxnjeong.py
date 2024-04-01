n=int(input())
factor=list(map(int,input().split()))
factor.sort()
print(factor[0]*factor[-1])