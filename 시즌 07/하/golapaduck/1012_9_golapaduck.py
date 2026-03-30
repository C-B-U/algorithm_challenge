import sys
text = sys.stdin.read()
stack = list(0 for i in range(0,27))
for char in text:
    char = ord(char) - 97
    if(char>=0):
        stack[char] += 1
for count in range(0,stack.count(max(stack))):
    print(chr(stack.index(max(stack))+97),end="")
    stack[stack.index(max(stack))] = 0