import sys
input = sys.stdin.readline

n = int(input())
stack = []

commands = {
    'push': lambda x: stack.append(x),
    'pop': lambda: print(stack.pop() if stack else -1),
    'size': lambda: print(len(stack)),
    'empty': lambda: print(1 if not stack else 0),
    'top': lambda: print(stack[-1] if stack else -1)
}

for _ in range(n):
    command = input().split()
    if command[0] == 'push':
        commands['push'](command[1])
    else:
        commands[command[0]]()