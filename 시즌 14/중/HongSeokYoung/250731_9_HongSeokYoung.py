# 백준 알고리즘 1082번 '방 번호' https://www.acmicpc.net/problem/1082

import sys

input = sys.stdin.readline

n = int(input())
price = list(map(int, input().split()))
m = int(input())

# 1. 가장 싼 숫자 찾기
minCost = 50
minNum = -1
for i in range(n):
    if price[i] <= minCost:
        minCost = price[i]
        minNum = i

# 2. 자리 수 확보
length = m // minCost
if length == 0:
    print(0)
    sys.exit(0)

# 3. 최소 숫자로 초기화
result = [minNum] * length
m -= minCost * length  # 남은 돈

# 4. 앞자리부터 교체
s = 0
for i in range(length):
    # 큰 수부터 탐색
    for j in range(n - 1, -1, -1):
        if price[j] <= m + minCost:
            result[i] = j
            m += minCost
            m -= price[j]
            break

    # 앞자리 0인 경우 제거 처리
    if result[s] == 0:
        s += 1
        m += minCost

# 5. 출력
if s == length:
    print(0)
else:
    print(''.join(map(str, result[s:])))