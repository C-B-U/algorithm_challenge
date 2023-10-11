n, k = map(int, input().split())
s = list(map(int, input().split()))

start = 0
end = max(s)
while start != end:
    sum = 0
    mid = int((start + end) /2)
    if mid == start:
        break
    for i in s:
        if (i-mid) >0:
            sum += (i-mid)
    if sum > k:
        start = mid
    elif sum < k:
        end = mid
    elif sum == k:
        break
print(mid)
