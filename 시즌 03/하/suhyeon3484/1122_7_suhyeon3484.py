# 14720 : 우유 축제

n = int(input())
milk = list(map(int, input().split()))

count = 0
for i in range(n):
    if milk[i] == count % 3:
        count += 1
print(count)