# 백준 알고리즘 1193 '분수찾기' 문제
X = int(input())

# 몇 번째 대각선인지 찾기
n = 1
while n * (n + 1) // 2 < X:
    n += 1

# 해당 대각선에서 몇 번째인지 계산
start = n * (n - 1) // 2 + 1
index = X - start

# 분수 찾기
if n % 2 == 0:  # 짝수 대각선
    numerator = 1 + index
    denominator = n - index
else:  # 홀수 대각선
    numerator = n - index
    denominator = 1 + index

print(f"{numerator}/{denominator}")