# 1357 : 뒤집힌 덧셈

import sys
input = sys.stdin.readline

a, b = input().rstrip().split()

rev_a = a[::-1]
rev_b = b[::-1]

sum = str(int(rev_a) + int(rev_b))
print(int(sum[::-1]))