n = int(input())
a= map(int,input().split())
count=0
for num in a:
    for i in range(2,num+1):
        if num==i:
            count+=1
        if num%i==0:
            break
print(count)