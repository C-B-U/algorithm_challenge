from cmath import cos
from collections import defaultdict

n = int(input())

frequency = defaultdict(int)

words = []
for _ in range(n):
    word = input()
    words.append(word)
    wordlen = len(word)
    for i, v in enumerate(word):
        frequency[v] += 10**(wordlen-i)

frequency = sorted(frequency.items(), key=lambda x: x[1], reverse=True)

costs = {}
cost = 9
for i in frequency:
    costs[i[0]] = str(cost)
    cost -= 1

total = 0
for i in words:
    total += int(''.join(list(map(lambda x: costs[x], i))))

print(total)