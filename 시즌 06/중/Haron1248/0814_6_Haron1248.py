r={}
for i in range(int(input())):
    x,y,z=map(int,input().split())
    r[i+1]=(x**2+y**2)**.5/z
for i,j in sorted(r.items(),key=lambda x:x[1]):
    print(i)
