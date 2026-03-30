# 백준 알고리즘 16507번 어두운 건 무서워

import sys
input = sys.stdin.readline

# 입력 받기
R, C, Q = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(R)]

# 2차원 누적 합 배열 생성
S = [[0] * (C + 1) for _ in range(R + 1)]

for i in range(1, R + 1):
    for j in range(1, C + 1):
        S[i][j] = A[i-1][j-1] + S[i-1][j] + S[i][j-1] - S[i-1][j-1]

# 질의 처리
for _ in range(Q):
    r1, c1, r2, c2 = map(int, input().split())
    
    # 부분합 구하기
    total_sum = S[r2][c2] - S[r1-1][c2] - S[r2][c1-1] + S[r1-1][c1-1]
    
    # 평균 밝기 (정수 나누기)
    num_elements = (r2 - r1 + 1) * (c2 - c1 + 1)
    print(total_sum // num_elements)
