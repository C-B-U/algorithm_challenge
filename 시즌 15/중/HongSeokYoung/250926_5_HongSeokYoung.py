# 백준 알고리즘 2805번 '나무 자르기' https://www.acmicpc.net/problem/2805

import sys
import bisect
input = sys.stdin.readline

n, m = map(int, input().split())
trees = list(map(int, input().split()))
trees.sort()

# 누적합 배열
prefix = [0] * (n + 1)
for i in range(1, n + 1):
    prefix[i] = prefix[i - 1] + trees[i - 1]

start, end = 0, trees[-1]
result = 0

while start <= end:
    mid = (start + end) // 2

    # mid보다 큰 나무 시작 index 찾기
    idx = bisect.bisect_right(trees, mid)

    # 잘린 길이 = (전체 합 - mid*개수)
    cut = prefix[n] - prefix[idx] - (n - idx) * mid

    if cut >= m:  # 충분히 잘림 → 높이 올려도 됨
        result = mid
        start = mid + 1
    else:  # 부족 → 낮춰야 함
        end = mid - 1

print(result)