from sys import stdin

n = stdin.readline()
x = list(map(int, stdin.readline().split(sep=" ")))
keys = sorted(list(set(x)))

value_maps = {}
for k, v in zip(keys, range(len(x))):
    value_maps[k] = v

for i in range(len(x)):
    x[i] = value_maps[x[i]]

print(*x)
