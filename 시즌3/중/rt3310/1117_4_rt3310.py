import sys
from collections import deque

input = sys.stdin.readline

m, n, k = map(int, input().split())

table = [[0 for i in range(n)] for j in range(m)]

for _ in range(k):
    ldx, ldy, rux, ruy = map(int, input().split())
    ldy = m - ldy
    ruy = m - ruy
    for i in range(ruy, ldy):
        table[i] = table[i][:ldx] + ([1] * (rux - ldx)) + table[i][rux:]

def search(table, start, m, n):
    d = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    q = deque([start])
    table[start[0]][start[1]] = 1
    
    count = 0
    while q:
        cur = q.popleft()
        count += 1
        for i in d:
            if cur[0] + i[0] < 0 or cur[0] + i[0] > m-1:
                continue
            if cur[1] + i[1] < 0 or cur[1] + i[1] > n-1:
                continue
            if table[cur[0]+i[0]][cur[1]+i[1]] == 1:
                continue
            q.append([cur[0]+i[0], cur[1]+i[1]])
            table[cur[0]+i[0]][cur[1]+i[1]] = 1
    return count

result = []
for i, iv in enumerate(table):
    for j, jv in enumerate(iv):
        if jv == 0:
            result.append(search(table, [i, j], m, n))
print(len(result))
print(*sorted(result))