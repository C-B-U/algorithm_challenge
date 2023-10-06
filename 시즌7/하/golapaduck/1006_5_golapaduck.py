a, b = map(int,input().split())
x,y = a,b
while(y):
    x,y=y,x%y
print(x)
print((a*b)//x)
