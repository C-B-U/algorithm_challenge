import sys

input = sys.stdin.readline
n, m = map(int, input().split())
titleTable = dict()
scoreKeys = []

result = 0
def BinarySearch(l, r, target):
    mid = l + (r - l) // 2
    if mid == r:
        return mid
    if target > scoreKeys[mid]:
        return BinarySearch(mid + 1, r, target)
    if target < scoreKeys[mid]:
        return BinarySearch(l, mid, target)
    return mid

for _ in range(n):
    titleName, num = input().split()
    num = int(num)
    scoreKeys.append(num)

    if num in titleTable.keys():
        continue

    titleTable[num] = titleName

for _ in range(m):
    score = int(input())
    print(titleTable[scoreKeys[BinarySearch(0, n, score)]])
