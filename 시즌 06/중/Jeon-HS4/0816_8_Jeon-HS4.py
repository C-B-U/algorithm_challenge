n = int(input())
a, b = map(int, input().split())

answer = 0
dots = set()

for i in range(n):
    x, y = map(int, input().split())
    dots.add((x, y))

for x, y in dots:
    if (x + a, y + b) in dots and (x + a, y) in dots and (x, y + b) in dots:
        answer += 1
print(answer)
