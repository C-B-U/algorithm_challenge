# 백준 알고리즘 2720 세탁소 사장 동혁 문제

def change(money):
    if(money >= Quarter):
        change_list[0] = money // Quarter
        money = money - change_list[0]*Quarter
    
    if(money >= Dime):
        change_list[1] = money // Dime
        money = money - change_list[1]*Dime
        
    if(money >= Nickel):
        change_list[2] = money // Nickel
        money = money - change_list[2]*Nickel
        
    if(money >= Penny):
        change_list[3] = money // Penny
        money = money - change_list[3]*Penny
        
    print(' '.join(map(str, change_list)))
    
    for i in range(len(change_list)):
        change_list[i] = 0

Quarter = 25
Dime = 10
Nickel = 5
Penny = 1

change_list = [0]*4

T = int(input())

for i in range(T):
    money = int(input())
    change(money)

# def change(money):
#     coins = [25, 10, 5, 1]
#     change_list = []

#     for coin in coins:
#         change_list.append(money // coin)
#         money %= coin

#     print(' '.join(map(str, change_list)))

# T = int(input())

# for i in range(T):
#     money = int(input())
#     change(money)