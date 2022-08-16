brackets = input()

stack = []
total = 0
tmp = 1
for idx, i in enumerate(brackets):
    if i == "(":
        tmp *= 2
        stack.append(i)
    elif i == "[":
        tmp *= 3
        stack.append(i)
    elif i == ")":
        if not stack or stack[-1] == "[":
            total = 0
            break
        if brackets[idx-1] == "(":
            total += tmp
        tmp //= 2
        stack.pop()
    else:
        if not stack or stack[-1] == "(":
            total = 0
            break
        if brackets[idx-1] == "[":
            total += tmp
        tmp //= 3
        stack.pop()

if stack:
    print(0)
else:
    print(total)