# 1일차, 최댓값

A = []
max = 0
result = 0

for i in range(9):
    A.append(int(input()))

for i in range(9):
    if max < A[i]:
        max = A[i]
        result = i + 1

print(max)
print(result)
