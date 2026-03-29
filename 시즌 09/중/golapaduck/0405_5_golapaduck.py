#28069
n,k = map(int,input().split())

result="water"
for _ in range(k):
    if (n % 3 == 2): n -=1
    else: n= min(2*(n+1)//3, n-1)
    
    if (n==0):
        result="minigimbob"
        break
    
print(result)