import sys

N = int(input())
tx, ty = map(int, input().split())
points = set()

for i in range(N):
    x, y = map(int, input().split())
    points.add((x, y))

rectangles = set()
for x, y in points:
    if (x + tx, y) in points and (x + tx, y + ty) in points and (x, y + ty) in points:
        rectangles.add(
            frozenset([(x, y), (x + tx, y), (x + tx, y + ty), (x, y + ty)]))
    if (x + tx, y - ty) in points and (x, y - ty) in points and (x + tx, y) in points:
        rectangles.add(
            frozenset([(x, y), (x + tx, y), (x + tx, y - ty), (x, y - ty)]))

sys.stdout.write(str(len(rectangles)))
