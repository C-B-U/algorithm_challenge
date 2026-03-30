# 백준 알고리즘 1110 '더하기 사이클'

number = int(input())
first = number
count = 0

while(True):
    ten = number // 10 % 10
    one = number % 10
    sumA = (ten + one) % 10

    newnumber = one * 10 + sumA

    count +=1
    
    number = newnumber
    
    if first == number:
        break

print(count)