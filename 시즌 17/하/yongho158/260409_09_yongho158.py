import sys
input = sys.stdin.readline

N, K = map(int, input().split())
arr = list(map(int, input().split()))

current = sum(arr[:K])
answer = current

for i in range(1, N):
    current -= arr[i - 1]
    current += arr[(i + K - 1) % N]
    answer = max(answer, current)

print(answer)
