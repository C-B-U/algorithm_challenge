import sys


def solve():
    data = sys.stdin.readline
    q = int(data().split()[0])

    a = 1
    b = 0
    pointer = 1

    results = []
    for _ in range(q):
        line = list(map(int, data().split()))
        t = line[0]

        if t == 3:
            results.append(str(a * pointer + b))
        else:
            n = line[1]
            if t == 0:
                b += n
            elif t == 1:
                a *= n
                b *= n
            elif t == 2:
                pointer += n

    sys.stdout.write("\n".join(results) + "\n")


if __name__ == "__main__":
    solve()