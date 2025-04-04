import sys
input = sys.stdin.readline

n = int(input())
first , sec = 0, 0


for _ in range(n):
    a , b = input().split()
    a , b = int(a) , int(b)

    if a > b:
        first += 1
    elif a < b:
        sec += 1

print(f"{first} {sec}")
