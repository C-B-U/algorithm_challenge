# 백준 알고리즘 1964 오각형, 오각형, 오각형… 문제

# def solve(n):
#     result = (3 * n * n + 5 * n + 2) // 2
#     return result % 45678

# n = int(input())
# print(solve(n))

n = 1

N = int(input())

for i in range(N):
    
    n = n + 1 + 3*(i+1)

n = n % 45678
    
print(n)