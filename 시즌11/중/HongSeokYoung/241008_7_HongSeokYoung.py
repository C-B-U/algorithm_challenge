# 백준 알고리즘 15649 'N과 M(1)' 문제

import sys
input = sys.stdin.read

N, M = map(int, input().split())
visited = [False] * N
sequence = []

def dfs():
    if len(sequence) == M:
        print(' '.join(map(str, sequence)))
        return
    
    for i in range(N):
        if not visited[i]:
            visited[i] = True
            sequence.append(i + 1)
            dfs()
            sequence.pop()
            visited[i] = False

dfs()