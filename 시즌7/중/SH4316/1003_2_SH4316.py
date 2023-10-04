m, n = map(lambda value: int(value), input().split(" "))

if m <= 1:
    m = 2
    if n <= 1:
        exit()

def isPrime(num):
    j = 2
    while num >= j**2:
        if num % j == 0:
            return False
        j += 1
    
    return True
    
for i in range(m, n+1):
    if isPrime(i):
       print(i)
