# 파이썬 라이브러리 풀이

from itertools import permutations
N, M = map(int, input().split())

for combination in permutations(range(1, N + 1), M):
    print(" ".join(map(str, combination)))

# 정석 풀이 : 재귀 백트래킹

N, M = map(int, input().split())
visited = [ False ] * (N + 1)

def dfs(sequence: list = []):
    if len(sequence) == M:
        print(*sequence)
        return None

    for num in range(1, N + 1):
        if not visited[num]:
            sequence.append(num)
            visited[num] = True
            dfs(sequence)
            sequence.pop()
            visited[num] = False
            
dfs()
