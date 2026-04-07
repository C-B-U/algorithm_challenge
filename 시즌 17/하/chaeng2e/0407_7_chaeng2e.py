K = int(input())

A = 1
B = 0

for _ in range(K):
    A, B = B, A + B

print(A, B)
