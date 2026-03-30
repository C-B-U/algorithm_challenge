# 1546 : 평균
import sys
input = sys.stdin.readline

n = int(input())
score = list(map(int, input().split()))

max = max(score)
sum = 0

for i in range(n):
    score[i] = score[i] / max * 100
    sum += score[i]

print(sum / n)
