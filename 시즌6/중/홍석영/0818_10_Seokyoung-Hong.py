import sys

sys.setrecursionlimit(1000000)


def find_min_len(min_len, ft=0,):
    t = ft
    if min_len == 0:
        return 1
    while t+min_len <= n:
        if Sl[t+min_len] - Sl[t] >= s:
            return find_min_len(min_len-1, t)
        # elif t+min_len+1 >= n:
        #     return min_len+1
        else:
            t += 1

    if min_len == len(Sl):
        return min_len+1
    elif Sl[min(n, ft+min_len+1)] - Sl[ft] >= s:
        return min_len+1
    return len(Sl)


global n
global S
global s

n, s = map(int, sys.stdin.readline().rstrip().split())
a = list(map(int, sys.stdin.readline().rstrip().split()))

min_len = n

Sl = [0, a[0]]
for i in range(1, n):
    Sl.append(Sl[i]+a[i])
del a


ans = find_min_len(min_len)
print(0 if ans > n else ans)
