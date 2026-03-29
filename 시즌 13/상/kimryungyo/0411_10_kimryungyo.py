# 삼각형이 성립하는 경우는 문제에서 주어진대로 A + B > C 일 때다.
# 그러므로 우선 정렬을 한 뒤 삼각형이 성립하는 경우들을 미리 계산한다.
# 그 후 비트마스킹 DP 이용해 긱 집합에서 가능한 최대 넓이 합을 구한 뒤 최댓값을 출력한다.

from math import sqrt

N = int(input().strip())
fences = list(map(int, input().split()))
fences.sort()

valids = []
for i in range(N):
    for j in range(i+1, N):
        for k in range(j+1, N):
            a, b, c = fences[i], fences[j], fences[k]

            if a + b > c:
                s = (a + b + c) / 2
                area = sqrt(s * (s - a) * (s - b) * (s - c))
                mask = (1 << i) + (1 << j) + (1 << k)
                valids.append((mask, area))

dp = [-1] * (2 ** N)
dp[0] = 0

for mask in range(2 ** N):
    if dp[mask] < 0: continue

    for sets, area in valids:
        if mask & sets == 0:
            new_mask = mask | sets
            if dp[new_mask] < dp[mask] + area:
                dp[new_mask] = dp[mask] + area

answer = max(dp)
print(answer)