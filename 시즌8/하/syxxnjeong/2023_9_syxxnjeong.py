N, M = map(int, input().split())
cards = list(map(int, input().split()))

result = 0
length = len(cards)

for i in range(0, length):
    for j in range(i+1, length):
        for k in range(j+1, length):
            sum_value = cards[i] + cards[j] + cards[k]
            if sum_value <= M:
                result = max(result, sum_value)

print(result)