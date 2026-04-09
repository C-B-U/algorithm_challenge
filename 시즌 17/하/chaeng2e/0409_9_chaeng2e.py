N, K = map(int, input().split())
A = list(map(int, input().split()))

A = A * 2

current_sum = sum(A[:K])
max_sum = current_sum

for i in range(1, N):
    current_sum = current_sum - A[i - 1] + A[i + K - 1]
    max_sum = max(max_sum, current_sum)

print(max_sum)
