n = int(input())
arr = list(map(int, input().split()))

sorted_arr = sorted(arr)

matching = {}
count = 0
for i in sorted_arr:
    if matching.get(i) is None:
        matching[i] = count
        count += 1

matched = list(map(lambda x: str(matching.get(x)), arr))

print(' '.join(matched))