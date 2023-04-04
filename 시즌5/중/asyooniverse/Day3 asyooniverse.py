import sys, math
from collections import Counter
input = sys.stdin.readline

n = int(input())
l = []
for i in range(n):
    input_ = int(input())
    l.append(input_)

l.sort()
count = Counter(l).most_common(2)

print(math.floor(sum(l)/len(l)+0.5))
print(l[len(l)//2])
if len(count) == 1 or count[0][1] != count[1][1]:
    print(count[0][0])
else:
    print(count[1][0])
print(max(l) - min(l))