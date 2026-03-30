from itertools import combinations as c

n, m, k = map(int, input().split())
a = c(range(n), m)
b = c(range(n), m)

deno, num = 0, 0
for i in a:
    for j in b:
        deno += 1
        if len(set(i) & set(j)) >= k:
            num += 1


print(num / deno)
