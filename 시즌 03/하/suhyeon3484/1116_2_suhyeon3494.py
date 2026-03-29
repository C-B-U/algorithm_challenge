# 10867 : 중복 뺴고 정렬하기

import sys

input = sys.stdin.readline
n = input()

num = list(map(int, input().split()))

for i in sorted(list(set(num))):
    print(i, end = ' ')