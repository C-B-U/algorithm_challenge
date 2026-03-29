import sys
input = sys.stdin.readline

n = int(input())
 
for _ in range(n):
    line = input().split()
    d = dict()
    t = int(line[0])
    max_value = 0
    max_key = 0

    for i in range(1, len(line)):
        num = int(line[i])

        if num not in d:
            d[num] = 1
        else:
            d[num] += 1

        if d[num] > max_value:
            max_value = d[num]
            max_key = num

    if max_value > t / 2:
        print(max_key)
    else:
        print('SYJKGW')