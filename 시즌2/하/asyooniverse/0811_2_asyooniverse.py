N = int(input())
M = 0

for i in range(1, N+1):        
    NL = list(map(int, str(i)))  
    s = i + sum(NL)              
    if(s == N):                 
        M = i                   
        break

print(M)