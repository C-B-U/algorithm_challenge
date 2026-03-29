import sys

N = int(sys.stdin.readline())
arr = list(range(10))

for i in arr:
    n = i % 10
    y = i * 10
    for x in range(n):
        arr.append(x + y)
print(arr[N] if N < len(arr) else -1)
