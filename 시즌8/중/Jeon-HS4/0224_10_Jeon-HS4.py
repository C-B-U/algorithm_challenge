vertex_num, edge_num = map(int, input().split())
edges = []
connected_edge = set()
cost = 0

def find(parent, vertex):
    if parent[vertex] == vertex:
        return vertex
    return find(parent, parent[vertex])

for _ in range(edge_num):
    new_edge = list(map(int, input().split()))
    edges.append(new_edge)

edges.sort(key=lambda x: x[2])

parent = [i for i in range(vertex_num + 1)]

for e in edges:
    root_a = find(parent, e[0])
    root_b = find(parent, e[1])

    if root_a != root_b:
        connected_edge.add(e[0])
        connected_edge.add(e[1])
        parent[root_b] = root_a
        cost += e[2]

print(cost)
