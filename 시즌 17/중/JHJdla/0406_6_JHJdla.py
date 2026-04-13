a = 0
b = 1
d =1
inp1 = [1] 
inp = [] 
cnffur = []
n = int(input())
for i in range(n):
    c= list(map(int , input().split()))
    
    if c[0] == 1:
        b *= c[1]
        a = c[1]*a
    elif c[0] == 0:
        a += c[1]
    elif c[0] == 2:
        d += c[1]
    else:
        cnffur.append(a+d*b)
        



for i in cnffur:
    print(i)