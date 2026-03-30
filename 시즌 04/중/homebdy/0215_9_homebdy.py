n = int(input())
firecrackers = list(map(int, input().split()))

for i in range(n-2):
    if i == n-3:
        firecrackers[-1] -= 1
        firecrackers[0] -= 1
        break
    if firecrackers[-1] >= firecrackers[0]:
        firecrackers[-1] -= 1
        continue
    firecrackers[0] -= 1

print(max(firecrackers[0], firecrackers[-1]))