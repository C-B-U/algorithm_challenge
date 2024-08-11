n = int(input())
num = list(map(int, input().split()))

result = max((i for i in range(n+1) if num.count(i) == i), default=-1)

print(result)