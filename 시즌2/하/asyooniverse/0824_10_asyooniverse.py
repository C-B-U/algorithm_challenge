com = int(input())
vertex = int(input())
array = [[] for _ in range(com+1)]
result = 0
visited = [False]*(com+1)
    
for _ in range(vertex):
    x, y = map(int, input().split())
    array[x].append(y)
    array[y].append(x)
 
def dfs(i):
    global result
    result += 1
    visited[i] = True
    for j in array[i]:
        if not visited[j]:
            dfs(j)
dfs(1)
print(result-1)