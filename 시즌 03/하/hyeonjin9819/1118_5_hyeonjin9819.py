T = input()
li = [0] * 9
for x in T:
    num = int(x)
    if num == 9:
        num = 6
    li[num] += 1
li[6] = (li[6]+1) // 2
print(max(li))