s1, s2 = input().split(" ")

def diff(s1, s2):
    c = 0
    for n in zip(list(s1), list(s2)):
        if (n[0] != n[1]):
            c += 1
    return c
min = 100
for i in range(len(s2) - len(s1) + 1):
    min_ = diff(s1, s2[i:len(s1)+i])
    if (min_ < min):
        min = min_
print(min)
