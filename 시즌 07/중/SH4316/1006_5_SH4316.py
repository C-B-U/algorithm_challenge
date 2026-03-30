def ccd(x1, y1, x2, y2):
    return x1*y2-x2*y1

points = []
for i in range(3):
    points.append(list(map(lambda value: int(value), input().split(" "))))

for point in points[1:]:
    point[0] -= points[0][0]
    point[1] -= points[0][1]

value = ccd(points[1][0], points[1][1], points[2][0], points[2][1]) 
if value > 0:
    value = 1
elif value < 0:
    value = -1

print(value)
