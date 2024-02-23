n = int(input())
tree = list(map(int, input().split()))
drop = int(input())

tree_node = [_ for _ in range(n) if _ != drop]
result = 0

def check_child(d_node):
  for i, parent in enumerate(tree):
    if(parent == d_node):
      check_child(i)
      tree_node.remove(i)

check_child(drop)

new_tree = [tree[t] for t in tree_node]
for node in tree_node:
  if node not in new_tree:
    result += 1
    
print(result)
