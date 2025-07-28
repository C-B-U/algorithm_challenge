# 백준 알고리즘 15723번 'n단 논법' https://www.acmicpc.net/problem/15723

from collections import deque

n = int(input())
graph = {chr(i): [] for i in range(ord('a'), ord('z')+1)}

# 관계 저장
for _ in range(n):
    a, _, b = input().split()
    graph[a].append(b)

m = int(input())

def is_related(start, target):
    visited = set()
    queue = deque([start])
    
    while queue:
        cur = queue.popleft()
        if cur == target:
            return True
        
        for nxt in graph[cur]:
            if nxt not in visited:
                visited.add(nxt)
                queue.append(nxt)
    return False

# 질의 처리
for _ in range(m):
    a, _, b = input().split()
    print("T" if is_related(a, b) else "F")