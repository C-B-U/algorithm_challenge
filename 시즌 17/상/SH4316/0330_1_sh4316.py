n = int(input())
c = 1

temp = 2

while n > temp:
    n -= temp
    c += 1
    temp *= 2

temp = 1
result = ""
n -= 1
for i in range(c):
    if (n & temp):
        result = '7' + result
    else:
        result = '4' + result
    temp *= 2
print(result)
