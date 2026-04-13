import sys
input = sys.stdin.readline

N = int(input())
S = input().rstrip()

ok = True

if S.count('H') != 2 * S.count('O'):
    ok = False

h = 0
o = 0
for c in S:
    if c == 'H':
        h += 1
    else:
        o += 1
    if o > h:
        ok = False
        break

if ok:
    h = 0
    o = 0
    for c in S[::-1]:
        if c == 'H':
            h += 1
        else:
            o += 1
        if o > h:
            ok = False
            break

print("pure" if ok else "mix")