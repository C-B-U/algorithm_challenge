import sys

n = int(sys.stdin.readline())
card = list(map(int, sys.stdin.readline().split()))

for i in range(n):
    if card[i] != 0:
        continue
    prev_card = 0
    next_card = 0
    if i != 0:
        prev_card = card[i-1]
    if i != n-1:
        next_card = card[i+1]
    for color in (1, 2, 3):
        if prev_card == color or next_card == color:
            continue
        card[i] = color
        break

for i in range(0, n-1):
        if i > 0 and card[i-1] == card[i]:
            print(-1)
            break
        if card[i+1] == card[i]:
            print(-1)
            break

else:
    print(*card)
