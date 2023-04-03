import sys
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().split()))
result = 0 

for x in l:
    count = 0
    if x == 1:
        continue
    for j in range(2, x):
        if x % j == 0:
            count += 1
    if count == 0:
        result += 1
                
print(result)