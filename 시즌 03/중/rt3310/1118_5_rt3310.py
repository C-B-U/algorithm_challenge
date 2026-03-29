import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

n, r, q = map(int, input().split())

relation = [[] for _ in range(n+1)]
tree = [[] for _ in range(n+1)]
size = [0] * (n+1)

for i in range(n-1):
    u, v = map(int, input().split())
    relation[u].append(v)
    relation[v].append(u)

def make_tree(current, parent):
    for node in relation[current]:
        if node != parent:
            tree[current].append(node)
            make_tree(node, current)

def count_subtree_nodes(current):
    size[current] = 1
    for node in tree[current]:
        count_subtree_nodes(node)
        size[current] += size[node]

make_tree(r, -1)
count_subtree_nodes(r)

for i in range(q):
    print(size[int(input())])