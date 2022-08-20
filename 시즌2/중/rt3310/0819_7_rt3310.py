n = int(input())

tree = ['.'] * 352
tree[1] = 'A'
for _ in range(n):
    node, left, right = input().split()
    for i in range(1, len(tree)):
        if tree[i] == node:
            if left != '.':
                tree[i*2] = left
            if right != '.':
                tree[i*2+1] = right
            break

def preorder(idx):
    print(tree[idx], end='')
    if idx*2 < 352 and tree[idx*2] != '.':
        preorder(idx*2)
    if idx*2+1 < 352 and tree[idx*2+1] != '.':
        preorder(idx*2+1)
        

def inorder(idx):
    if idx*2 < 352 and tree[idx*2] != '.':
        inorder(idx*2)
    print(tree[idx], end='')
    if idx*2+1 < 352 and tree[idx*2+1] != '.':
        inorder(idx*2+1)
        
def postorder(idx):
    if idx*2 < 352 and tree[idx*2] != '.':
        postorder(idx*2)
    if idx*2+1 < 352 and tree[idx*2+1] != '.':
        postorder(idx*2+1)
    print(tree[idx], end='')
    
preorder(1)
print()
inorder(1)
print()
postorder(1)