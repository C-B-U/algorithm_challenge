import sys
input = sys.stdin.readline

N = int(input())
words = [input().strip() for _ in range(N)]

weight = {}

for word in words:
    length = len(word)
    for i in range(length):
        char = word[i]
        value = 10 ** (length - i - 1)
        
        if char in weight:
            weight[char] += value
        else:
            weight[char] = value

sorted_weights = sorted(weight.values(), reverse=True)

num = 9
result = 0

for w in sorted_weights:
    result += w * num
    num -= 1

print(result)