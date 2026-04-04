import sys

input = sys.stdin.readline
H, N = map(int, input().split())

lights = []
for i in range(N):
    r, c = map(int, input().split())
    lights.append((c, i))

lights.sort(key=lambda x: x[0])

ans = [0] * N

for k in range(N):
    original_idx = lights[k][1]
    ans[original_idx] = k + 1

print("YES")
print(*ans)#