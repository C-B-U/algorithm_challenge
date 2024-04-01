N = int(input())
fList = list(map(int,input().split()))
for i in range(N-3):
    if(fList[0]>fList[-1]):
        fList[0]-=1
    else:
        fList[-1]-=1
fList[0]-=1; fList[-1]-=1
print(max(fList[0],fList[-1]))