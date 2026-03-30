L = int(input())
N = int(input())
rollCake = [0]*(L+1)
received = [0]*(N+1)
maxPieces, wantMaxNum = 0,0

for i in range(1,N+1):
    count=0
    P, K=map(int,input().split())

    wantPieces = K-P
    if maxPieces < wantPieces:
        maxPieces = wantPieces
        wantMaxNum = i

    for j in range(P, K+1):
        if rollCake[j] == 0:
            rollCake[j] = i
            count += 1
    received[i] = count
print('<<출력>>')
print(wantMaxNum)
print(received.index(max(received)))