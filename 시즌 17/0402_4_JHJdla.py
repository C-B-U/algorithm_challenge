from bisect import bisect_left
a = list(map(int, input().split()))

wjwkd = []
wjwkd1 = []
wjwkddyd = []
c = 0
for i in range(a[0]):

        b= input().split()
        
        wjwkddyd.append(int(b[1]))
        wjwkd.append(b[0])
        

for j in range(a[1]):
    d = int(input())
    if wjwkddyd[len(wjwkd)-1] < d:
            continue
    else:
        wjwkd1.append(wjwkd[bisect_left(wjwkddyd,d)])



for i in wjwkd1:
    print(i)