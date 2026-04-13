
import sys
input = sys.stdin.readline

p = 1
FUNCS = [
    lambda s, x: s + x,
    lambda s, x: s * x,
    lambda s, n, p: s + p * n,
    lambda s: print(s)
]
s = 1

Q = int(input())

for _ in range(Q):
    inp = input().split()
    inp[0] = int(inp[0])
    match inp[0]:
        case 0:
            s = FUNCS[0](s, int(inp[1]))
        case 1:
            s = FUNCS[1](s, int(inp[1]))
            p *= int(inp[1])
        case 2:
            s = FUNCS[2](s, int(inp[1]), p)
        case 3:
            FUNCS[3](s)