n = int(input())
d = int(input())

if n == 1:
    print(8 * d)
elif n == 5:
    print(4 + 8 * d)
elif n == 3:
    print(2 + 4 * d)
elif n == 2:
    if d % 2 == 0:
        print(1 + 8 * (d // 2))
    else:
        print(3 + 4 * d)
elif n == 4:
    if d % 2 == 0:
        print(3 + 4 * d)
    else:
        print(5 + 8 * (d // 2))
