n = int(input())
buildings = list(map(int, input().split()))
result = [0]*(n)
if n == 1:
    print(0)
    exit()

def get_tilt(cidx, nidx):
    x1, x2 = cidx, nidx
    y1, y2 = buildings[cidx], buildings[nidx]
    return (y1 - y2) / (x1 - x2)

for i in range(n):
    tilt = float('INF')
    res = 0
    for j in range(i-1, -1, -1):
        if (tmp:=get_tilt(i, j)) < tilt:
            tilt = tmp
            res += 1

    tilt = -float('INF')  
    for k in range(i+1, n):
        if (tmp:=get_tilt(k, i)) > tilt:
            tilt = tmp
            res += 1
    result[i] = res

print(max(result))