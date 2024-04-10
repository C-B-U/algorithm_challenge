def dfs(x, y, num):
    if len(num) == 6:
        if num not in result:
            result.append(num)
        return
        
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    for k in range(4):
        ddx = x + dx[k]
        ddy = y + dy[k]
        
        if 0 <= ddx < 5 and 0 <= ddy < 5:
            dfs(ddx, ddy, num + n_list[ddx][ddy])

n_list = [list(map(str, input().split())) for _ in range(5)]

result = []
for i in range(5):
    for j in range(5):
        dfs(i, j, n_list[i][j])
print(len(result))