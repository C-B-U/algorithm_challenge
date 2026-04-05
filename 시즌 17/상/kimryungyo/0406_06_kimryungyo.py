# 재귀로 스택 처리

def process(arr: list, idx: int):
    if len(arr) >= 3:
        if idx >= 2 and arr[idx-2] == "A" and arr[idx-1] == "B" and arr[idx] == "B":
            del arr[idx]
            arr[idx-2] = "B"
            arr[idx-1] = "A"
            process(arr, idx-2)

N = int(input())
for _ in range(N):
    stack = []
    str_len = int(input())
    for char in input():
        stack.append(char)
        process(stack, len(stack)-1)
    print("".join(stack))
