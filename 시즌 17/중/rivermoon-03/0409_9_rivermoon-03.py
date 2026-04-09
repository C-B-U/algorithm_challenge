import sys  
input = sys.stdin.readline

n = int(input())
words = []
for _ in range(n):
    words.append(input().strip())

weight_dict = {}

for word in words:
    length = len(word)
    for i in range(length):
        char = word[i]
        pow = 10 ** (length - i - 1)
        
        if char in weight_dict:
            weight_dict[char] += pow
        else:
            weight_dict[char] = pow
sorted_weights = sorted(weight_dict.values(), reverse=True)

total_sum = 0
number = 9

for weight in sorted_weights:
    total_sum += weight * number
    number -= 1

print(total_sum)
    