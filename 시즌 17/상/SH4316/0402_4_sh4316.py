import sys

n, m = map(int, input().split(" "))

for i in range(1, n+1):
    for j in range(1, m+1):
        if (i + j)%2 == 0:
            continue
        print("?", i, j)
        sys.stdout.flush()
        if input() == "1":
            exit()
