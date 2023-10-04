X = int(input())
N = int(input())

total = []

for i in range(N):
    a, b = map(int, input().split())
    total.append(a*b)

total_price = sum(total)

if total_price == X:
    print("Yes")
else:
    print("No")
