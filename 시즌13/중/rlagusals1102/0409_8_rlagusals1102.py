def solve(a, b, points):
    point_set = set(points)
    cnt = 0

    for x, y in points:
        if ((x + a, y) in point_set and
                (x, y + b) in point_set and
                (x + a, y + b) in point_set):
            cnt += 1

    return cnt


n = int(input())
a, b = map(int, input().split())
points = [tuple(map(int, input().split())) for _ in range(n)]

print(solve(a, b, points))
