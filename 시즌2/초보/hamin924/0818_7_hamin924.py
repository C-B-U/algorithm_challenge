for i in range(int(input())):
    N, M, k, D = map(int, input().split())
    b = 2*D//(k*N*M*(M-1) + M*M*N*(N-1))
    if b:
        print(M*(M-1)*N*k*b//2 + M*M*N*(N-1)*b//2)
    else:
        print(-1)