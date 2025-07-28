# 백준 알고리즘 2512번 '예산' https://www.acmicpc.net/problem/2512

n = int(input())
budgets = list(map(int, input().split()))
m = int(input())

left, right = 0, max(budgets)
result = 0

while left <= right:
    mid = (left + right) // 2
    total = 0

    # 상한액(mid)을 적용했을 때 총 예산 합
    for b in budgets:
        total += min(b, mid)

    if total <= m:
        result = mid     # 현재 상한액(mid)을 저장
        left = mid + 1   # 더 큰 상한액 가능 여부 확인
    else:
        right = mid - 1  # 예산 초과 → 상한액 줄임

print(result)