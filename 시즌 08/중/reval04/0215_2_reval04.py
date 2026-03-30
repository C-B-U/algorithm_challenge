a,b = list(input().split())
min = 51
for i in range(len(b) - len(a) +1):
    c = 0
    for j in range(len(a)):
        if a[j] != b[j + i]:
            c += 1
    if min >= c:
        min = c
print(min)
