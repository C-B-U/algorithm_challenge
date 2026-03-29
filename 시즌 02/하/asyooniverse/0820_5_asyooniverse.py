import sys
input = sys.stdin.readline

n = int(input())
stack = []

for i in range(n):
    s = input().split()
    if s[0] == 'push':
        stack.append(int(s[1]))
    elif s[0] == 'top':
        if len(stack) > 0: print(stack[-1])
        else: print(-1)
    elif s[0] == 'pop':
        if len(stack) > 0: print(stack.pop())
        else: print(-1)
    elif s[0] == 'size':
        print(len(stack))
    elif s[0] == 'empty':
        if len(stack) > 0: print(0)
        else: print(1)