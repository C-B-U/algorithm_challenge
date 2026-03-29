from sys import stdin,stdout

input, print = stdin.readline, stdout.write

n, d, k, c = map(int, input().split())
arr = [int(input()) for _ in range(n)]

cnt = [0] * (d + 1)

uniq_type = 0

chk = False

for i in range(k):
    s = arr[i]

    if cnt[s] == 0:
        uniq_type += 1

    cnt[s] += 1

    if s == c:
        chk = True

max_var = uniq_type + (0 if chk else 1)

for i in range(n):
    l = arr[i]
    cnt[l] -= 1

    if cnt[l] == 0:
        uniq_type -= 1

        if l == c:
            chk = False

    e = arr[(i + k) % n]

    if cnt[e] == 0:
        uniq_type += 1

    cnt[e] += 1

    if e == c:
        chk = True

    max_var = max(max_var, uniq_type + (0 if chk else 1))

print(f"{max_var}")

