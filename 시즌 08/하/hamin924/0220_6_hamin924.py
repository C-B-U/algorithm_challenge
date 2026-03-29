# 약수

n = int(input())

a = list(map(int, input().split()))

a.sort()

result = a[0] * a[-1]

print(result)