# 더하기 사이클

n = int(input())
num = n
count = 0

while True:
    count += 1
    plus = num // 10 +  num % 10
    num = num % 10 * 10 + plus % 10
    if num == n:
        break

print(count)
