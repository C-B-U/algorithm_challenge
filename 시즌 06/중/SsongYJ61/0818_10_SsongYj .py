n,s = map(int,input().split())
arr = list(map(int, input().split()))

start, end = 0, 0
sum = arr[0]
ans = 100001

while True :
    if sum < s :
        end += 1
        if end == n :
            break
        sum += arr[end]
    else :
        sum -= arr[start]
        ans = min(ans, end - start + 1)
        start += 1

print(ans if ans != 100001 else 0)
