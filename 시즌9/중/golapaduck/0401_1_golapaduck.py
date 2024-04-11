# 21557
count = int(input())
stack = list(map(int,input().split()))
left = stack[0]
right = stack[count-1]

for i in range(0,count-2):
    if i == count-3:
        left = left-1
        right = right-1
        break
    if left > right:
        left = left-1
    else:
        right = right-1

print(max(left,right))