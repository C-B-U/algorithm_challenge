num = int(input())
card = [i for i in range(1, num+1)]

for i in range(len(card)):
    if len(card) == 1:
        print(card[0])
    else :
        print(card.pop(0), end=' ')
        back = card.pop(0)
        card.append(back)