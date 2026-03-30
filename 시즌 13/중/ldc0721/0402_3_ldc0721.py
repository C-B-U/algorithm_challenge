n = int(input())
d = [[0]*100 for _ in range(100)]
a = 0
#색종이 크기 입력
for i in range(n) :
    x,y = map(int, input().split())
    for m in range(y,y+10):
        for n in range(x,x+10) :
            d[n][m] = d[n][m] + 1

for i in range(100):
    for j in range(100):
        if d[j][i] >=1 :
            a += 1
        else :
            continue

print(a)
