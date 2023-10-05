import sys
N = int(input())

adj_matrix = []
for _ in range(N):
    adj_matrix.append([int(x) for x in sys.stdin.readline().rstrip().split()])

for k in range(N):
    for i in range(N):
        for j in range(N):
            if adj_matrix[i][k] == 1 and adj_matrix[k][j] == 1:
                adj_matrix[i][j] = 1

for row in adj_matrix:
    print(' '.join(map(str,row)))