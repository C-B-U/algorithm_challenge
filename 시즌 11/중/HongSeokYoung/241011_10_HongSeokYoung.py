# 백준 알고리즘 14503번 '로봇 청소기' 문제

from collections import deque

# 방향 벡터 (북, 동, 남, 서)
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def turn_left(d):
    return (d + 3) % 4

def clean_room(n, m, r, c, d, room):
    visited = [[False] * m for _ in range(n)]
    visited[r][c] = True
    queue = deque([(r, c, d)])
    cleaned_count = 1

    while queue:
        x, y, direction = queue.popleft()
        cleaned = False

        for _ in range(4):
            direction = turn_left(direction)
            nx, ny = x + dx[direction], y + dy[direction]

            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny] and room[nx][ny] == 0:
                visited[nx][ny] = True
                queue.append((nx, ny, direction))
                cleaned_count += 1
                cleaned = True
                break

        if not cleaned:
            back_direction = (direction + 2) % 4
            bx, by = x + dx[back_direction], y + dy[back_direction]

            if room[bx][by] == 0:
                queue.append((bx, by, direction))
            else:
                break

    return cleaned_count

# 입력 받기
n, m = map(int, input().split())
r, c, d = map(int, input().split())
room = [list(map(int, input().split())) for _ in range(n)]

# 결과 출력
print(clean_room(n, m, r, c, d, room))
