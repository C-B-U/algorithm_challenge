arr: list[list[int]] = [[0] * 100 for _ in range(100)]
cnt = 0


for _ in range(int(input())):
    n, m = map(int, input().split())

    for i in range(m, m + 10):
        for j in range(n, n + 10):
            if not arr[i][j]:
                cnt += 1
                arr[i][j] = 1

print(cnt)
