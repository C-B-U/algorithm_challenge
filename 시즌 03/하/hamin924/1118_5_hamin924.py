N = input()

lst = [0]*10

for i in range(len(N)):
    num = int(N[i])
    if num == 6 or num == 9:
        if lst[6] <= lst[9]:
            lst[6] += 1
        else:
            lst[9] += 1
    else:
        lst[num] += 1
 
print(max(lst))
