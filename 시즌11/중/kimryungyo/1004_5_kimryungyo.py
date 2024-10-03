# 역시 에드혹은 어렵다..
# 풀이 : 크기가 같은 그릇이 가장 많은 그릇의 수가 답이다.

from collections import Counter
N, *nums = map(int, open(0).read().split())
print(max(Counter(nums).values()))
