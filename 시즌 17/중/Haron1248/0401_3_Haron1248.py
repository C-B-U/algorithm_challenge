n, m = map(int, input().split())
if n == 1:
    arr = [1]
elif n == 2:
    arr = [1, 1, 2]
else:
    arr = [(n + 2) // 3, n // 2, (n + 1) // 2]
    for i in range(3):
        for j in range(i + 1, 3):
            arr.append(arr[i] + arr[j])
    arr.append(n + (n + 2) // 3)

cnt = 1
for v in arr:
    if v > m:
        break
    cnt += 1
print(cnt)
