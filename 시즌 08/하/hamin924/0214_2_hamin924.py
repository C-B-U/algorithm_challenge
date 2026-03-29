# 2일차, 펠린드롬

str = list(input())

str_reverse = str[::-1] # 역순


if str == str_reverse:
    print("1")
else:
    print("0")