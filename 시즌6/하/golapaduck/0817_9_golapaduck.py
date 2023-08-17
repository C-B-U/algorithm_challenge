s=list(map(int,input().split()))
a=s[0]
b=s[1]
c=s[2]

if(b>=c):
    print(-1)
else:
    print(int(a/(c-b)+1))