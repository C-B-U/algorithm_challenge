import sys

input = sys.stdin.readline

n = int(input())
square = []
for i in range(n):
    square.append(input().split())

counts = {'0': 0, '1': 0}
def search(square, sx, ex, sy, ey):
    stand = square[sy][sx]
    if ex-sx == 1:
        counts[stand] += 1
        return
    
    for i in range(sy, ey):
        if str(abs(int(stand)-1)) in square[i][sx:ex]:
            break
    else:
        counts[stand] += 1
        return
    
    xmid = (sx+ex) // 2
    ymid = (sy+ey) // 2
    search(square, sx, xmid, sy, ymid)
    search(square, xmid, ex, sy, ymid)
    search(square, sx, xmid, ymid, ey)
    search(square, xmid, ex, ymid, ey)

search(square, 0, n, 0, n)
print(counts['0'])
print(counts['1'])