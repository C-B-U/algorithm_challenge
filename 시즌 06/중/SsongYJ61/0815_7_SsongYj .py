n, l = map(int, input().split())
data = list(map(int, input().split()))

# 정렬
data.sort()

cnt = 1
start = data[0] - 0.5
end = start + l

for i in range(n) :
    if start < data[i] < end :
        continue
    else :
        cnt += 1
        start = data[i] - 0.5
        end = start + l

print(cnt)

