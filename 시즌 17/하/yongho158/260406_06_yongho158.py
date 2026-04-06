n = int(input())

counts = list(map(int, input().split()))

max_true = -1

for i in range(n + 1):
    true_count = counts.count(i)

    if true_count == i:
        max_true = max(max_true, i)

print(max_true)
