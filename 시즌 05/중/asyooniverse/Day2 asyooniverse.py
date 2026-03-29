import sys
input = sys.stdin.readline

n = int(input())
cards = list(input().split())
m = int(input())
set_ = list(input().split())
result = {}

for i in set_:
    result[i] = 0

for i in cards:
    if i not in result:
        continue
    result[i] += 1
    
for i in set_:
    print(result[i], end=' ')