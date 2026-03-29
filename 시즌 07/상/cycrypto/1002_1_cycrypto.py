n, k = map(int, input().split())
prefix = list(map(int, input().split()))
arr = [0]*len(prefix)
arr[0] = prefix[0]
for i in range(1, len(prefix)):
    arr[i] = prefix[i] + arr[i-1]

cache = {0:1}
res = 0

for i in range(len(arr)):
    if arr[i]-k in cache.keys():
        # print(cache[arr[i]-k])
        res += cache[arr[i]-k]

    if arr[i] not in cache.keys():
        # print("a2")
        cache[arr[i]] = 1

    else:
        # print("a3")
        cache[arr[i]] += 1


    # print(cache, res)

# print(arr)
print(res)