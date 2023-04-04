n = int(input())


def check_line(n):
    if n == 1:
        return 1
    i,j,c = 1,6,1
    while True:
        c += 1
        i += j
        if i >= n:
            return c
        j+=6

print(check_line(n))