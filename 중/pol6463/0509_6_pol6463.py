n = int(input())

count = 1

def hanoi(n, x, y, z):
    if n == 1:
        print(x, z)
    else:
        hanoi(n-1, x, z, y)
        print(x, z)
        hanoi(n-1, y, x, z)

for i in range(n-1):
    count = count * 2 + 1

print(count)
hanoi(n, 1, 2, 3)