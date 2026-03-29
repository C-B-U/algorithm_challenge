# 백준 알고리즘 14248 '점프점프' 문제

from collections import dequ제제

def bfs(start, stones):
    n = len(stones)
    visited = [False] * n
    queue = deque([start])
    visited[start] = True
    count = 1

    while queue:
        current = queue.popleft()
        jump = stones[current]

        for next_pos in (current + jump, current - jump):
            if 0 <= next_pos < n and not visited[next_pos]:
                visited[next_pos] = True
                queue.append(next_pos)
                count += 1

    return count

# 입력 받기
n = int(input())
stones = list(map(int, input().split()))
start = int(input()) - 1  # 시작 위치는 1부터 시작하므로 0으로 맞춰줌

# 결과 출력
print(bfs(start, stones))
