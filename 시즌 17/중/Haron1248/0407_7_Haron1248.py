s = list(input())
t = list(input())
while len(t) > len(s):
    if t[-1] == 'A':
        t.pop()
    else:
        t.pop()
        t = t[-1::-1]
print(int(s == t))
