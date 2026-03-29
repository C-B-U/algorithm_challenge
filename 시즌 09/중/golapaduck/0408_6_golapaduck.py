#9471
import sys

def solution(n):
    answer = 1
    first, second = 1, 2
    while True:
        if (first % n == 1) & (second % n == 1):
            break
    
        answer += 1
        first, second = second, (first + second) % n
    
    return answer

count = int(sys.stdin.readline())

for _ in range(count):
    n, m = map(int,sys.stdin.readline().split())
    answer = solution(m)
    print(f"{n} {answer}")