n, s = map(int, input().split())
arr = list(map(int, input().split()))

start, end = 0, 0
sum = arr[0]
answer = 100001

while True:
    if sum < s:
        end += 1
        if end == n:
            break
        sum += arr[end]
    else:
        sum -= arr[start]
        answer = min(answer, end - start + 1)
        start += 1
        
print(answer if answer != 100001 else 0)
