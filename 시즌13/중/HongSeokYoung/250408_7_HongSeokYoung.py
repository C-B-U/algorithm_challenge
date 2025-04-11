# 백준 알고리즘 1359번 '복권' https://www.acmicpc.net/problem/1359

import math

def comb(n, r):
    if r > n:
        return 0
    return math.comb(n, r)

N, M, K = map(int, input().split())

total_cases = comb(N, M)
win_cases = 0

for i in range(K, M + 1):
    win_cases += comb(M, i) * comb(N - M, M - i)

probability = win_cases / total_cases

print(f"{probability:.10f}")