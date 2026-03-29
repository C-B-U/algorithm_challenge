menu_count = int(input())
menu_price = [int(input()) for _ in range(menu_count)]
M = int(input())
buy_menu = [int(input()) for _ in range(M)]
sum = 0

for i in range(M):
    sum += menu_price[int(buy_menu[i]) - 1]


print(sum)
