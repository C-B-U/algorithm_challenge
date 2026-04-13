k = int(input())
a = 1
b = 0

for _ in range(k):
    temp = a
    a = b
    b = temp + b

print(a, b)
