points = []


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    @staticmethod
    def ccw(p1, p2, p3):
        return (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - (p2.x*p1.y + p3.x*p2.y + p1.x*p3.y))


for _ in range(3):
    points.append(Point(*map(int, input().split())))

ccw = Point.ccw(points[0], points[1], points[2])

if ccw > 0:
    print(1)
elif ccw < 0:
    print(-1)
else:
    print(0)
