size = int(input())
arr = list(map(int, input().split()))

# 정렬
arr = (list(set(arr)))
arr.sort()

for i in arr:
    print(i,end=' ')