N = int(input())
arr = list(float(input()) for _ in range(N))
for i in range(1, N):
    arr[i] = max(arr[i], arr[i] * arr[i - 1])
print('%0.3f' % max(arr))