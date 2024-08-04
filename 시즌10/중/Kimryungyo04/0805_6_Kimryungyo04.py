stack = []
N = int(input())

for _ in range(N):
    command = input().split()

    if command[0] == 'push':
        stack.append(int(command[1]))

    elif command[0] == 'pop':
        if stack: print(stack.pop())
        else: print(-1)
    
    elif command[0] == 'size':
        print(len(stack))
    
    elif command[0] == 'empty':
        if stack: print(0)
        else: print(1)
    
    elif command[0] == 'top':
        if stack: print(stack[-1])
        else: print(-1)
