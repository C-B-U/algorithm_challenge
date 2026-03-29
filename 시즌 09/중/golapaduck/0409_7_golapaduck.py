#2312
import sys

case = int(sys.stdin.readline())

for _ in range(case):
    num = int(sys.stdin.readline())
    i = 2
    while i*i <= num:
        count = 0
        while (num % i == 0):
            num //= i
            count += 1

        if count: sys.stdout.write(f"{i} {count}\n")
        
        i += 1
        
    if num > 1:
        sys.stdout.write(f"{num} 1\n")