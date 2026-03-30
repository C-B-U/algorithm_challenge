list = []

while True:
    a = int(input())
    if a == 0 :
        break
    else:
        list.append(a)


for i in list:

    while i >= 10:
        sum = 0
        for j in str(i):
            sum += int(j)
        i = sum
    print(i)
                
