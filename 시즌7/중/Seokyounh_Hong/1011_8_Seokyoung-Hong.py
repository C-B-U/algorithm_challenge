n, m = map(int, input().split())

trees = list(map(int, input().split()))

s, e = 1, max(trees)

while s <= e:
    mid = (s+e)//2

    killed_tree = 0
    for tree in trees:
        if tree > mid:
            killed_tree += tree - mid

    if killed_tree >= m:
        s = mid + 1
    else:
        e = mid - 1

print(e)
