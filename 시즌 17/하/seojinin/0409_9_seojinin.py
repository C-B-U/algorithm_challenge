n, k = map(int, input().split())
arr = list(map(int, input().split()))

current = sum(arr[:k])
answer = current

for i in range(1, n):
    current -= arr[i - 1]
    current += arr[(i + k - 1) % n]
    answer = max(answer, current)

print(answer)
