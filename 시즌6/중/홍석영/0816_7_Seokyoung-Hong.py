import sys

n, length = map(int, sys.stdin.readline().rstrip().split())

points = list(map(int, sys.stdin.readline().rstrip().split()))
points.sort()

num_of_lines = 0
numI = 0

while numI < len(points):
    i = points[numI]
    for numJ in range(numI+1, len(points)):
        j = points[numJ]
        numI = numJ

        if abs((i - 0.5)-(j + 0.5)) <= length:
            continue
        else:
            break

    else:
        numI += 1

    num_of_lines += 1


sys.stdout.write(str(num_of_lines))
