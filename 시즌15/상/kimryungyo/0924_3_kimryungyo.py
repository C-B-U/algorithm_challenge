# 문자를 하나씩 스택에 추가하면서 skeep이 발견되면 * 으로 대체
# *은 s를 제외한 모든 문자가 될 수 있음
# 's를 제외한' 문자만 가능함에 주의..

n = int(input())
string = input()

def check(stack):
    if len(stack) < 5: return False
    key = "skeep"
    for i in range(-1, -6, -1):
        char = stack[i]
        if char == "*" and key[i] != "s": continue
        if char != key[i]: return False
    return True

count = 0
stack = []
for char in string:
    stack.append(char)
    while check(stack):
        del stack[-5:]
        stack.append("*")
        count += 1

print(count)