n = int(input())
numbers = list()
for _ in range(n):
    a, b = map(int, input().split())
    numbers.append(b - a)

numbers = sorted(numbers)

answer = 0
if len(numbers) % 2 == 0:
    start = len(numbers) // 2 - 1
    answer = numbers[start + 1] - numbers[start] + 1
else:
    answer = 1

print(answer)
