import sys

for i in range(int(sys.stdin.readline())):
    a, b = map(int, sys.stdin.readline().split())
    if (b % a == 0) and (b // a != 1): 
        print(1)
    else:
        print(0)