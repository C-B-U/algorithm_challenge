import sys
from collections import defaultdict, deque

def solution():
    def bfs(graph, from_node, to_node):
        queue = deque([(from_node, 0)])
        visited = [0] * (N+1)
        while queue:
            node, distance = queue.popleft()
            if node == to_node:
                return distance
            for next_node, next_distance in graph[node]: 
                if not visited[next_node]:
                    visited[next_node] = 1
                    queue.append((next_node, next_distance+distance))
        

        
    N, M = map(int, input().split())
    tree = defaultdict(list)

    for i in range(N-1):
        node_one, node_two, distance = map(int, sys.stdin.readline().rstrip().split())
        tree[node_one].append((node_two, distance))
        tree[node_two].append((node_one, distance))

    
    for j in range(M):
        fnode_one, fnode_two = map(int, sys.stdin.readline().rstrip().split())
        total_distance = bfs(tree, fnode_one, fnode_two)
        print(total_distance)

if '__main__' == __name__:
    solution()