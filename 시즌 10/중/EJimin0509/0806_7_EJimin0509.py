from collections import Counter

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

count_a = Counter(a)

result = 0
for num in b:
    if count_a[num] > 0:
        count_a[num] -= 1
    else:
        result += 1

print(result)
