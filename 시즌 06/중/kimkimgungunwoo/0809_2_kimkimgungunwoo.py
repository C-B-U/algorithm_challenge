import sys
N=int(sys.stdin.readline().strip())
dlist=[]
for i in range(N):
    dlist.append(int(sys.stdin.readline().strip()))
dlist.sort()
i=N-1
while i>1:
    if dlist[i]<sum(dlist[i-2:i]):
        break
    else:
        i-=1
if i!=1:
    print(sum(dlist[i-2:i+1]))
else:
    print(-1)
    
        
    

