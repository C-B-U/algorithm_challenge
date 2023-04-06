n, k = map(int, input().split())
A = list(map(int, input().split(',')))
for i in range(k):
    t = []
    for j in range(len(A)-1):
        t.append(A[j+1]-A[j])
    A = t.copy()
print(','.join(list(map(str, A))))
