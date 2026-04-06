n = int(input())
array = list(map(int, input().split()))

cnt = [0] * 51

for x in array:
    cnt[x] += 1

ans = -1

for i in range(51):
    if cnt[i] == i:
        ans = i

print(ans)
