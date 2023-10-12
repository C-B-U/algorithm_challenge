def bfs(n,m): # array라는 배열 안에 칸 마다 각 칸까지 도착가능한 횟수를 입력
    q = [n]
    while q:
        now = q.pop(0)  # 큐의 첫 원소 탐색
        if(now == m):  # 도착하면 return
            return array[now]
            
        for next in (now-1, now+1, now*2): # 다음 이동 구간 동안 한번 더 탐색
            if(0 <= next < MAX and not array[next]):  # 범위를 넘지 않으면서 list에 next 값이 없을 경우
                array[next] = array[now] + 1  # 
                q.append(next)

MAX = 100001
n, m = map(int, input().split())
array = [0]*MAX

print(bfs(n,m))
