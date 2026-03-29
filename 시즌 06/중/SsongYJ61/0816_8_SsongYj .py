import sys

n = int(sys.stdin.readline())
a,b = map(int, sys.stdin.readline().split())

lst = []
cnt = 0

for i in range(n) :
    point = tuple(map(int, sys.stdin.readline().split()))
    lst.append(point)

set_lst = set(lst)


for p in lst:
    w, h = p
    p1 = (w + a, h)
    p2 = (w, h+b)
    p3 = (w+a, h+b)

    if (p1 in set_lst) and (p2 in set_lst) and (p3 in set_lst):
        cnt += 1

print(cnt)
