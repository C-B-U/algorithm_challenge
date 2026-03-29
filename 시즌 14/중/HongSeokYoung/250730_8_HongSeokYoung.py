# 백준 알고리즘 14888번 '연산자 끼워넣기' https://www.acmicpc.net/problem/14888

import sys

# 입력 처리
n = int(sys.stdin.readline().strip())
numbers = list(map(int, sys.stdin.readline().split()))
add, sub, mul, div = map(int, sys.stdin.readline().split())

# 최댓값, 최솟값 초기화
max_val = -float('inf')
min_val = float('inf')

# 백트래킹 함수
def dfs(idx, result, add, sub, mul, div):
    global max_val, min_val
    
    # 모든 숫자를 사용한 경우 최댓값, 최솟값 갱신
    if idx == n:
        max_val = max(max_val, result)
        min_val = min(min_val, result)
        return

    # 연산자 사용 (덧셈)
    if add > 0:
        dfs(idx + 1, result + numbers[idx], add - 1, sub, mul, div)
    
    # 연산자 사용 (뺄셈)
    if sub > 0:
        dfs(idx + 1, result - numbers[idx], add, sub - 1, mul, div)

    # 연산자 사용 (곱셈)
    if mul > 0:
        dfs(idx + 1, result * numbers[idx], add, sub, mul - 1, div)

    # 연산자 사용 (나눗셈) (Python의 // 연산이 음수 나눗셈에서 다르게 동작하므로 보정)
    if div > 0:
        if result < 0:
            dfs(idx + 1, -(-result // numbers[idx]), add, sub, mul, div - 1)
        else:
            dfs(idx + 1, result // numbers[idx], add, sub, mul, div - 1)

# DFS 실행
dfs(1, numbers[0], add, sub, mul, div)

# 결과 출력
print(max_val)
print(min_val)