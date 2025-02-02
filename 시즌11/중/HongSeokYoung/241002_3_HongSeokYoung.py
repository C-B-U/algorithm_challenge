# 백준 알고리즘 23351 '물주기' 문제

index = 0
count = 0

N, K, A, B = map(int, input().split())

flower = [K] * N

limit = len(flower) - 1

while True:
    if 0 in flower:
        break
    
    else:
        for _ in range(A):
            if index > limit:
                index = 0
            flower[index] += B
            index += 1
        flower = [x - 1 for x in flower]
        count += 1 

print(count)