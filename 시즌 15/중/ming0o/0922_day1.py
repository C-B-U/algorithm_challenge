n, k = map(int, input().split())
arr = list(map(int, input().split()))
arr.extend(arr)

ans = 0
visited = [0] * 200002

for i in range(1, n*2 + 1):
    visited[i] = visited[i-1] + arr[i-1]

for i in range(k, n*2 + 1):
    ans = max(ans, visited[i] - visited[i-k])
    
    
print(ans)