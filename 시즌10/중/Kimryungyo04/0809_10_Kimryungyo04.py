# N개가 참이라는 말이 N개 존재하면 참이다.

from collections import Counter
n, *nums = map(int, open(0).read().split())

counts = dict(Counter(nums))
result = 0 if counts.get(0, 0) == 0 else -1

for answer, count in counts.items():
    if answer == count:
        result = max(result, count)

print(result)
