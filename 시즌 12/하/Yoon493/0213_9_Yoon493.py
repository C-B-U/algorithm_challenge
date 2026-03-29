N = int(input())
numbers = list(map(int, input().split()))
total = 0

for num in numbers:
    if num == 1:
        continue

    for i in range(2, num + 1):
        if num % i == 0:
            if num == i:
                total += 1
            break

print(total)