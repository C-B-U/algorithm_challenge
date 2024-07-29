n = int(input())

if n==1 or n==2:
    result = 0
elif n==3:
    result = 1
else:
    result = 2
    d = 2
    cnt = 0
    for i in range(n-4):
        result += d
        cnt += 1
        if cnt == 2:
            cnt = 0
            d += 1
print(result)