num_list = []
for i in range(10):
    num_list.append(int(input()))

distance = 100
sum = 0
num = 0
for n in num_list:
    sum += n
    if distance >= abs(100-sum):
        distance = abs(100-sum)
        num = sum

print(num)
