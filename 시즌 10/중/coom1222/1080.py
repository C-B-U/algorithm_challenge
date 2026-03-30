import numpy as np

# 뒤집기 함수 정의
def Flip_Matrix(matrix, x, y):
    for i in range(3):
        for j in range(3):
            matrix[x+i][y+j] = 1 - matrix[x+i][y+j]

# 행렬의 크기 입력
N, M = map(int, input(" ").split())

if N > 50 or M > 50:
    exit()

# 행렬 A 입력
ar1 = []
for _ in range(N):
    row = list(map(int, input().strip()))
    ar1.append(row)
ar1 = np.array(ar1)

# 행렬 B 입력
ar2 = []
for _ in range(N):
    row = list(map(int, input().strip()))
    ar2.append(row)
ar2 = np.array(ar2)

cnt = 0

# 행렬 변환 연산 수행
for i in range(N-2):
    for j in range(M-2):
        if ar1[i][j] != ar2[i][j]:
            Flip_Matrix(ar1, i, j)
            cnt += 1

# 변환 완료 후 두 행렬 비교
if np.array_equal(ar1, ar2):
    print(cnt)
else:
    print(-1)k