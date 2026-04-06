n = int(input())

ary = [0] * 46
ary[1] = 1

for i in range(2, 46):
    ary[i] = ary[i - 1] + ary[i - 2]

print(ary[n - 1], ary[n]) 
