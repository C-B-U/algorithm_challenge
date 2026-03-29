n = int(input())
s1 = set(input().split())

m = int(input())
s2 = list(input().split())
result = []

for i in s2:
    if i in s1:
        result.append("1")
    else:
        result.append("0")

print(*result)