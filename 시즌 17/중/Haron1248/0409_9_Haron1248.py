table = dict()
words = []
for _ in range(int(input())):
    word = list(input())
    words.append(word)
    size = len(word)
    for i in range(len(word)):
        c = word[i]
        if c in table.keys():
            table[c] += 10 ** (size - i - 1)
            continue
        table[c] = 10 ** (size - i - 1)

temp = [str(v) for v in range(10)]
rankTable = dict([(arr[0], temp.pop()) for arr in sorted(table.items(), key=lambda x:(-x[1], x[0]))])

total = 0
for word in words:
    s = ""
    for c in word:
        s += rankTable[c]
    total += int(s)
print(total)
