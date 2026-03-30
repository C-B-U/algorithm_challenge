n = int(input())
a = input().split()
m = int(input())
arr = input().split()
checks = [None] * m

a.sort()

for i in range(len(arr)):
    pl = 0
    pr = len(a) - 1

    while True:
        pc = (pl + pr) // 2
        
        if a[pc] == arr[i]:
            checks[i] = 1
            break
        elif a[pc] < arr[i]:
            pl = pc + 1
        else:
            pr = pc - 1
            
        if pl > pr:
            checks[i] = 0
            break

for j in checks:
    print(j)