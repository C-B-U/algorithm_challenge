import sys
input = sys.stdin.readline

n = int(input())
b = list(input().strip())

h = 0
o = 0
i = 0

while(True):
    if i >= n:
        break

    if b[i] == "H":
        h += 1
    else:
        o += 1

    if o > h:
        print("mix")
        exit(0)

    i += 1

if h != o * 2:
    print("mix")
    exit(0)

h = 0
o = 0
i = n - 1

while(True):
    if i < 0:
        break

    if b[i] == "H":
        h += 1
    else:
        o += 1

    if o > h:
        print("mix")
        exit(0)

    i -= 1

print("pure")