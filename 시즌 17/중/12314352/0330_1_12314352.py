a, b = map(int,input(":").split())
res = 1
if a >= b :
    print(0)
else:
    for i in range(1,a+1):
        res = (res*i)%b
    print(res)
