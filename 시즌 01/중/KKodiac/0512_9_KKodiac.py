def solution():
    # table[n, k] = table[n, k-1] + table[n-1, k]
    N, K = map(int, input().split())
    table = [0] * (N+1)
    table[0] = 1
    for _ in range(K):
        for  i in range(1, N+1):
            table[i] = (table[i] + table[i-1])
    print(table[N]%1000000000)

if '__main__' == __name__:
    solution()