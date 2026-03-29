m,n=map(int,input().split())

for i in range(m,n+1):
    if i ==1 : #1은 소수가 아님
        continue
    for j in range(2,int(i**0.5)+1):
        if i%j==0: #약수가 존재하므로 소수가 아님
            break   
    else:
        print(i)