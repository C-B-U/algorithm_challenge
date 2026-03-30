import sys

n = int(input())
stack = []
      
for i in range(n):
    s = sys.stdin.readline().split()
    
    if s[0] == 'push':
        stack.append(s[1])
    
    elif s[0] == 'pop':
        if len(stack) == 0:
            print("-1")
        else:
            print(stack[-1])
            stack.pop()
    elif s[0] == 'size':
        print(len(stack))
    elif s[0] == 'empty':
        if len(stack) == 0:
            print("1")
        else:
            print("0")
    elif s[0] == 'top':
        if len(stack) == 0:
            print("-1")
        else:
            print(stack[-1])
