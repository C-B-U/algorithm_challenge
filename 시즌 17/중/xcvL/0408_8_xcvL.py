import sys
input = sys.stdin.readline

N, K, X = map(int, input().split())
a = list(map(int, input().split()))

prefix = [0] * (N + 1)
for i in range(N):
    prefix[i+1] = prefix[i] + a[i]

def can(L):
    for l in range(1, N - L + 2):
        r = l + L - 1
        income = X * prefix[l-1] + (prefix[N] - prefix[r])
        if income >= K:
            return True
    return False

left, right = 0, N
answer = -1

while left <= right:
    mid = (left + right) // 2
    if can(mid):
        answer = mid
        left = mid + 1
    else:
        right = mid - 1

print(answer if answer > 0 else -1)