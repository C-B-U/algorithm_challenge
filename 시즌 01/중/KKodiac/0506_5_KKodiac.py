import sys
from collections import defaultdict, deque

def solution():
    """ 정점이 많은 애들은 작은 값 부터 순서대로 방문하는 것에 유의 """
    input = sys.stdin.readline
    N, M, V = map(int, input().split())
    graph = defaultdict(list)
    
    for _ in range(M):
        node_one, node_two = map(int, input().split())
        graph[node_one].append(node_two)
        graph[node_two].append(node_one)

    def dfs(graph, start):
        stack = [start]
        visited = []
        while stack:
            n = stack.pop()
            if n not in visited:
                visited.append(n)
                temp = list(set(graph[n]) - set(visited))
                temp.sort(reverse=True)
                stack.extend(temp)
        
        return visited


    def bfs(graph, start):
        queue = deque([start])
        visited = []
        while queue:
            n = queue.popleft()
            if n not in visited:
                visited.append(n)
                temp = list(set(graph[n]) - set(visited))
                temp.sort()
                queue.extend(temp)

        return visited

    print(*dfs(graph, V))
    print(*bfs(graph, V))


if '__main__' == __name__:
    solution()