T = int(input())

data = list(map(int, input().split()))
cnt = 0

for i in range(T):
    a = data[i]/max(data) * 100
    cnt += a
print(cnt / T)
