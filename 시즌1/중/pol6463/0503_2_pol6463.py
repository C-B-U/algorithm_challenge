future, now = map(int, input().split())

n = int(input())
array = list(map(int, input().split()))

totalNum = 0
for i in range(n):
    totalNum += array[n-1-i] * pow(future, i)

res = []

while(totalNum > 0):
    y = totalNum % now
    res.insert(0, y)
    totalNum //= now


for i in res:
    print(i, end=" ")
