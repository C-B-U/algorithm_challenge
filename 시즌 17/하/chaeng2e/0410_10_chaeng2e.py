n, m = map(int, input().split())

print(0, 1)

current = 2

for _ in range(m - 1):
    print(1, current)
    current += 1

for i in range(current, n):
    print(i - 1, i)
