from collections import deque

m, n, h = list(map(int, input().split()))

direct = [[0, -1, 0], [0, 0, 1], [0, 1, 0], [0, 0, -1], [1, 0, 0], [-1, 0, 0]]
box = []
for i in range(h):
    tmp = []
    for j in range(n):
        tmp.append(list(map(int, input().split())))
    box.append(tmp)

tomatos = []
for i in range(h):
    for j in range(n):
        for k in range(m):
            if box[i][j][k] == 1:
                tomatos.append([i, j, k])


def search(initlist):
    q = deque(initlist)
    while q:
        curh, curx, cury = q.popleft()
        for i in direct:
            seekh = curh + i[0]
            seekx = curx + i[1]
            seeky = cury + i[2]
            if seekh >= 0 and seekh < h and seekx >= 0 and seekx < n and seeky >= 0 and seeky < m:
                if box[seekh][seekx][seeky] == 0:
                    q.append([seekh, seekx, seeky])
                    box[seekh][seekx][seeky] = box[curh][curx][cury] + 1


search(tomatos)

def get_status(box):    
    status = 1
    for i in box:
        for j in i:
            for k in j:
                if k == 0:
                    status = 0
                    return status
                if k > status:
                    status = k
    return status

print(get_status(box=box)-1)