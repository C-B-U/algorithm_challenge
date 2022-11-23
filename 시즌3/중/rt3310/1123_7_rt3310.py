import sys, math

input = sys.stdin.readline

n, l = map(int, input().split())
arr = sorted(list(map(int, input().split())))

stand = arr[0]
idx = 1
result = 1
while idx < n:
    if arr[idx] < stand + l:
        idx += 1
        continue
    
    stand = arr[idx]
    result += 1

print(result)