# 예전에 작성한 코드 제출 / 브루트포스

n = int(input())

nums = list(map(int, input().split()))
if n == 1: print("A"); quit()

num1, num2 = nums[0], nums[1]

def validate(a, b):
    result = num1
    for i in range(1, n):
        if nums[i] != (result := result * a + b): return False
    return True

pattern = None

for i in range(-200, 200):
    a, b = i, num2 - (num1 * i)
    if validate(a, b) == True:
        if pattern == None: pattern = (a, b)
        elif (nums[-1] * pattern[0] + pattern[1]) != (nums[-1] * a + b): print("A"); quit()

if pattern == None: print("B")
else: print(nums[-1] * pattern[0] + pattern[1])