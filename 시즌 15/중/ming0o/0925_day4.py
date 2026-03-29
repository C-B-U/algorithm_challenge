import sys
input = sys.stdin.readline
N = int(input())

_max = int(-1e9)
_min = int(1e9)

numbers = list(map(int, input().split()))
add, sub, mul, div = map(int, input().split())

def dfs(idx, _sum, add, sub, mul, div):
    global _max, _min
    if idx == N:
        _max = max(_max, _sum)
        _min = min(_min, _sum)
        return
    
    if add:
        dfs(idx+1, _sum + numbers[idx], add-1, sub, mul, div)

    if sub:
        dfs(idx+1, _sum - numbers[idx], add, sub-1, mul, div)
        
    if mul:
        dfs(idx+1, _sum * numbers[idx], add, sub, mul-1, div)
        
    if div:
        dfs(idx+1, _sum // numbers[idx] if _sum > 0 else -((-_sum)//numbers[idx]), add, sub, mul, div-1)

dfs(1, numbers[0], add, sub, mul, div)

print (_max)
print (_min)