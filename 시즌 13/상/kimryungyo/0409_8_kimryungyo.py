# 예전에 작성한 코드 제출

n = int(input())
prices = list(map(int, input().split()))
money = int(input())

if len(prices) == 1: print(0); quit()

min_all = min(prices)
min_without_0 = min(prices[1:])

length = (money - min_without_0) // min_all + 1
if length == 0: print(0); quit()

number = ""
for i in range(length):
    for num, price in sorted(enumerate(prices), reverse=True):
        if (money - price) >= ((length - i - 1) * min_all):
            number += str(num)
            money -= price

if number == "": print(0); quit()
print(number)