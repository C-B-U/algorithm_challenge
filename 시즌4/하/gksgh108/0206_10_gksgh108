N, M = map(int, input().split())
array = []
for _ in range(N):
    array.append(list(map(int, input().split())))

K = int(input())
for _ in range(K):
    i, j, x, y = map(int, input().split())
    result = 0
    for row in range(i-1, x):
        for col in range(j-1, y):
            result += array[row][col]
    print(result)
