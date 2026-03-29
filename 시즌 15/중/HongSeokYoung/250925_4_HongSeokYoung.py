# 백준 알고리즘 15658번 '연산자 끼워넣기 (2)' https://www.acmicpc.net/problem/15658

import sys
input = sys.stdin.readline

n = int(input().strip())
numbers = list(map(int, input().split()))
add, sub, mul, div = map(int, input().split())

max_val = -float('inf')
min_val = float('inf')

def dfs(idx, result, add, sub, mul, div):
    global max_val, min_val
    
    # 모든 숫자를 사용한 경우
    if idx == n:
        max_val = max(max_val, result)
        min_val = min(min_val, result)
        return

    # 덧셈
    if add > 0:
        dfs(idx + 1, result + numbers[idx], add - 1, sub, mul, div)
    # 뺄셈
    if sub > 0:
        dfs(idx + 1, result - numbers[idx], add, sub - 1, mul, div)
    # 곱셈
    if mul > 0:
        dfs(idx + 1, result * numbers[idx], add, sub, mul - 1, div)
    # 나눗셈
    if div > 0:
        if result < 0:
            dfs(idx + 1, -(-result // numbers[idx]), add, sub, mul, div - 1)
        else:
            dfs(idx + 1, result // numbers[idx], add, sub, mul, div - 1)

# 시작: 첫 번째 숫자 사용
dfs(1, numbers[0], add, sub, mul, div)

print(max_val)
print(min_val)