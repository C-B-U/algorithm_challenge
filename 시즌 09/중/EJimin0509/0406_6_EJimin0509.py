import sys

def pisano(x):
    if len(fibo) > x:
        return fibo[x]
    else:
        fibo[x] = (pisano(x-1)+pisano(x-2)) % m
        return fibo[x]


def cycle():
    x = 1
    while True:
        if fibo[x] == 0 and fibo[x-1] == 1:
            return x
        x += 1
        pisano(x)


for _ in range(int(input())):
    fibo = dict()
    fibo[0] = 0
    fibo[1] = 1
    fibo[2] = 1
    a, m = map(int, sys.stdin.readline().split())

    print(a, cycle())