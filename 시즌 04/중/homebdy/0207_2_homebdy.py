def sum(n):
    if n == 1:
        return 1
    elif n == 2:
        return 2
    elif n == 3:
        return 4
    return sum(n-3) + sum(n-2) + sum(n-1)

n = int(input())

for i in range(n):
    t = int(input())
    print(sum(t))