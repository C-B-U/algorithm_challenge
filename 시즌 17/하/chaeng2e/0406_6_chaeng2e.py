N = int(input())
arr = list(map(int, input().split()))

count = [0] * 51

for x in arr:
    count[x] += 1

answer = -1

for T in range(N + 1):
    if count[T] == T:
        answer = max(answer, T)

print(answer)
