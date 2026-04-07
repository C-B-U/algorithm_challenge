n = int(input())
d = list(map(int, input().split()))
q = int(input())
act = [list(map(int, input().split(" "))) for i in range(q)]

for a in act:
    if a[0] == 1:
        i = a[1]-1
        p = a[2]
        while p > 0 and i >= 0:
            m = min(d[i], p)
            p -= m
            d[i] = d[i] + m
            i -= 1

        i = a[1]
        p = a[2]
        while p > 0 and i < len(d):
            m = min(d[i], p)
            p -= m
            d[i] = d[i] + m
            i += 1

        continue
    if a[0] == 2:
        print(d[a[1]-1])
        continue
