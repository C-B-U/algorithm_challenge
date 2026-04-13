import sys
input = sys.stdin.readline

s = list(input().strip())
t = list(input().strip())

while len(t) > len(s):
    if t[-1] == 'A':
        t.pop()
    elif t[-1] == 'B':
        t.pop()
        t.reverse()

print(int(s == t))