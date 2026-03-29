# 백준 알고리즘 11896 다각형 문제

def sum_of_even_polygons(a, b):
    if a < 3:
        a = 3
    
    if a % 2 != 0:
        a += 1
    
    if b < 3:
        return 0

    if b % 2 != 0:
        b -= 1
    
    if a > b:
        return 0
    
    n = (b - a) // 2 + 1
    return (a + b) * n // 2

a, b = map(int, input().split())

print(sum_of_even_polygons(a, b))