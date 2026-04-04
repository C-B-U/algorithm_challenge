import sys

def read_input():
    data = sys.stdin.buffer.read().split()
    h = int(data[0])
    n = int(data[1])
    lights = []
    for i in range(n):
        r = int(data[2 + 2 * i])
        c = int(data[3 + 2 * i])
        lights.append((c, r, i))
    return h, n, lights


def solve():
    h, n, lights = read_input()
    lights.sort()
    dist = [0] * n
    for d in range(1, n + 1):
        _, _, idx = lights[d - 1]
        dist[idx] = d
    print("YES")
    sys.stdout.write(' '.join(map(str, dist)) + '\n')


if __name__ == "__main__":
    solve()