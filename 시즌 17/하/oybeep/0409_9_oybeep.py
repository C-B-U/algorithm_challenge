N, K = map(int, input().split())
A = list(map(int, input().split()))

A = A + A

current = sum(A[:K])
max_sum = current

for i in range(K, N + K):
    current += A[i]
    current -= A[i-K]
    max_sum = max(max_sum, current)

print(max_sum)
