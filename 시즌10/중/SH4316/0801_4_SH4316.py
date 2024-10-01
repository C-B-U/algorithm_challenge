n = int(input())
v = []

for i in range(n):
    v.append(int(input()))
# v.sort()

value = {0: [1, 0], 1: [0, 1]}
def get(n):
    val = value.get(n)
    if (val == None):
        v1 = get(n-1)
        v2 = get(n-2)
        result = [v1[0] + v2[0], v1[1] + v2[1]]
        value[n] = result
        return result
    return val

for i in range(n):
    val = get(v[i])
    print(val[0], val[1])
