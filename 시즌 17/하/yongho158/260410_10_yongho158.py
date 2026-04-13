n, m = map(int, input().split())

# 0 - 1 - 2 - ... - (n-m) 경로 만들기
for i in range(n - m):
    print(i, i + 1)

# 남은 정점들을 모두 (n-m)에 붙이기
for i in range(n - m + 1, n):
    print(n - m, i)
