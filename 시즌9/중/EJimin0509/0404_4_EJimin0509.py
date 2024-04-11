prefix = [0] * 1000001
cnt = [0] * 1000001

prefix[1] = 2
for i in range(2, 500001):
    prefix[i] = prefix[i - 1] + i + 1

for i in range(1, 500001):
    for j in range(i - 1, 0, -1):
        if prefix[i] - prefix[j] + j + 1 > 1000000:
            break
        cnt[prefix[i] - prefix[j] + j + 1] += 1

while True:
    n = int(input())
    if n == 0:
        break
    if n == 1:
        print(0)
    else:
        print(cnt[n] + 1)