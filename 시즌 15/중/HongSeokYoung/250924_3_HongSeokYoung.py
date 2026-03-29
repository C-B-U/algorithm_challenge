# 백준 알고리즘 1541번 '잃어버린 괄호' https://www.acmicpc.net/problem/1541

expr = input().split('-')

# 첫 그룹 (그냥 더함)
result = sum(map(int, expr[0].split('+')))

# 이후 그룹 (전부 더해서 빼기)
for e in expr[1:]:
    result -= sum(map(int, e.split('+')))

print(result)