n = int(input())
save = []
weight = {}

for _ in range(n):
    s = input().strip()
    save.append(s)

for word in save:
    length = len(word)
    for i in range(length):
        ch = word[i]
        value = 10 ** (length - i - 1)
        if ch in weight:
            weight[ch] += value
        else:
            weight[ch] = value

sorted_weight = sorted(weight.items(), key=lambda x: x[1], reverse=True)

num = 9
save2 = {}

for ch, _ in sorted_weight:
    save2[ch] = num
    num -= 1

ma = 0
for word in save:
    a = ''
    for ch in word:
        a += str(save2[ch])
    ma += int(a)

print(ma)