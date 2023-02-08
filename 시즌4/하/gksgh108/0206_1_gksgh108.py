N = int(input())
cnt = 0
start = N
while 1:
    a = start//10
    b = start%10
    c = (a+b)%10
    start = (b*10) + c
    cnt += 1

    if(start == N):
        break

print(cnt) 
