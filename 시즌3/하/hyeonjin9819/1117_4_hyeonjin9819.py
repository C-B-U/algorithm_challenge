ans = []
T = int(input())
li = list(map(int,input().split()))

for i in range(T):
    ans.insert(li[i],i+1)
print(*ans[::-1])