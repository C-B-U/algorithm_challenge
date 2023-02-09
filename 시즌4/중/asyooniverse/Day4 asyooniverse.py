from collections import deque

def bfs():
    queue = deque([n])
    while queue:
        x = queue.popleft()
        # 수빈이와 동생의 위치가 같다면 종료
        if x==k:
            print(visited[x])
            break
        for i in (x-1, x+1, x*2):
            if 0 <= i <= max_num and not visited[i]:
                visited[i] = visited[x] + 1
                queue.append(i)


max_num = 1000000
visited = [0] * (max_num+1)
n, k = map(int, input().split())
bfs()