import sys

N = int(sys.stdin.readline())
straw_list = []
for i in range(N):
    straw_list.append(int(sys.stdin.readline()))

straw_list.sort(reverse=True)
ans = -1

for t in range(N - 2):
    if straw_list[t] < straw_list[t + 1] + straw_list[t + 2]:
        ans = straw_list[t] + straw_list[t + 1] + straw_list[t + 2]
        break

print(ans)
