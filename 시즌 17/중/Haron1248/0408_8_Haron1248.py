import sys

input = sys.stdin.readline
n, k, x = map(int, input().split())
arr = list(map(int, input().split()))

leftArr = [0] * (n + 1)
for i in range(n):
    leftArr[i + 1] = leftArr[i] + arr[i] * x

rightArr = [0] * (n + 1)
for i in range(n - 1, -1, -1):
    rightArr[i] = rightArr[i + 1] + arr[i]

def check(l):
    for i in range(n - l + 1):
        if leftArr[i] + rightArr[i + l] >= k:
            return True
    return False

left = 0
right = n
result = -1
while left <= right:
    mid = (left + right) // 2
    if check(mid):
        result = mid
        left = mid + 1
    else:
        right = mid - 1

print(result if result else -1)
