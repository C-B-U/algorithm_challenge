# 백준 알고리즘 2903 중앙 이동 알고리즘 문제

N = int(input())

number = 2
count = 1

for i in range(N):
    number = number + count
    count = count*2

total = number * number

print(total)