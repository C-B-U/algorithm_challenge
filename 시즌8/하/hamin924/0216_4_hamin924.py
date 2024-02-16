# 소인수분해 

n = int(input())

for i in range(2, n+1):
    if n % i == 0: 
        while n % i == 0: # 나눌 수 없을 때 까지 나누기
            print(i)
            n = n / i
            if n == 1:
                break
