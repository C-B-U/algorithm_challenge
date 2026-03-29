n = int(input())
my_cards = list(map(int, input().split()))
m = int(input())
cards = list(map(int, input().split()))

my_cards.sort()

arr =[-10, 2, 3, 6, 10]

for card in cards:
    start = 0
    end = n - 1
    while start <= end:
        mid = (start + end) // 2
        if my_cards[mid] == card:
            print(1, end=" ")
            break
        elif my_cards[mid] > card:
            end = mid - 1
        else:
            start = mid + 1
    else:
        print(0, end=" ")