import sys

input = sys.stdin.readline
h, n = map(int, input().split())
lights = dict()
for i in range(n):
    r, c = map(int, input().split())
    if not c in lights.keys():
        lights[c] = [i]
        continue
    lights[c].append(i)

result = [0] * n
k = 1
for key in sorted(lights.keys()):
    arr = lights[key]
    for idx in arr:
        result[idx] = k
        k += 1

print("YES")
print(*result)
