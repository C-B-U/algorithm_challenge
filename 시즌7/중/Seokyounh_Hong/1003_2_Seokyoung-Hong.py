import math
m, n = map(int, input().split())

numbers = [True for i in range(n + 1)]

for i in range(2, int(math.sqrt(n)) + 1):
    if numbers[i]:
        j = 2
        while i * j <= n:
            numbers[i * j] = False
            j += 1

for i in range(m, n + 1):
    if numbers[i]:
        if i != 1:
            print(i)
