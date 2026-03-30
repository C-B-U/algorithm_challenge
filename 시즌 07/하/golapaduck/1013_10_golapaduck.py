count = int(input())
stack = list(i for i in range(1,count+1))
for i in range(0,count):
    print(stack.pop(0), end=" ")
    if(i < count-1):
        stack.append(stack.pop(0))