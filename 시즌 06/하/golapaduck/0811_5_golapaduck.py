number = list(map(int, input().split()))
i=0
while sorted(number) != number:
    if number[i] > number[i+1]:
        number[i], number[i+1] = number[i+1], number[i]
        print(*number)
    i = (i+1)%4