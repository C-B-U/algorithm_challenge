v = int(input())
# c = 0
m = {1: 0}
for i in range(2, v+1):
    min = 1000000
    if i % 3 == 0:
        min = m[i // 3]
    if i % 2 == 0:
        if min > m[i // 2]:
            min = m[i // 2]
    if min > m[i-1]:
        min = m[i-1]
    m[i] = min + 1
    
print(m[v])
