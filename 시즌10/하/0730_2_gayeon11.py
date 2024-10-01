#set: 중복을 허용하지 않음, 순서가 없음

N=int(input())
li=[]

for _ in range(N):
    x, y = map(int,input().split())
    for i in range(y, y+10):
        for j in range(x, x+10):
            li.append(i*100 + j)

print(len(list(set(li))))