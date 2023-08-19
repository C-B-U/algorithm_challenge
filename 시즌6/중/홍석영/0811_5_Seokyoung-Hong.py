import sys

n = int(sys.stdin.readline().rstrip())

graph = []
for i in range(n):
    graph.append(list(map(int, sys.stdin.readline().rstrip())))


def chk(x, y, n):
    if n == 1:
        return graph[x][y]

    stand = graph[x][y]
    for i in range(x, x+n):
        for j in range(y, y+n):
            if graph[i][j] != stand:
                n //= 2
                return f'({chk(x, y, n)}{chk(x, y+n, n)}{chk(x+n, y, n)}{chk(x+n, y+n, n)})'

    return stand


print(chk(0, 0, n))
