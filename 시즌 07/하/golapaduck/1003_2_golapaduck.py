price = int(input())
count = int(input())
for i in range(count):
    a,b = map(int,input().split())
    price -= a*b
if(price==0):
    print("Yes")
else:
    print("No")