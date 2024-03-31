N = int(input())
A = list(map(int, input().split()))

i = N - 2
while i:
    if i == 1:
        A[0] -= 1
        A[N - 1] -= 1
    else:
        if A[0] >= A[N - 1]:
            A[0] -= 1
        else:
            A[N - 1] -= 1
    i -= 1

if A[0] >= A[N - 1]:
    print(A[0])
else:
    print(A[N - 1])