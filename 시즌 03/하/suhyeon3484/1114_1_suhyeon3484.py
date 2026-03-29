# 25551 멋쟁이 포닉스

mask_white, mask_black = map(int, input().split())
t_white, t_black = map(int, input().split())
pants_white, pants_black = map(int, input().split())

list1 = [mask_white, t_black, pants_white]
list2 = [mask_black, t_white, pants_black]

min1 = min(list1)
min2 = min(list2)

if min1 == min2:
    other = 0
else:
    other = 1

result = min(min1, min2) * 2 + other

print(result)