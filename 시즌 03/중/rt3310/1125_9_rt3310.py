while True:
    string = input()

    if string == '.':
        break
    
    bracket = {']':'[', ')':'('}
    stack = []
    correct = True
    for i in string:
        if i == '(' or i == '[':
            stack.append(i)
            continue
        if i == ')' or i == ']': 
            if stack and stack[-1] == bracket.get(i):
                stack.pop()
                continue
            else:
                correct = False
                break
    
    if stack:
        correct = False
    
    if correct:
        print('yes')
    else:
        print('no')