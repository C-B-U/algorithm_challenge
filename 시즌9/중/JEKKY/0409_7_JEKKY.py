R = int(input())
for i in range(R):
    N = int(input())
    m = N
    prime = [0]*100000
    for j in range(2,m+1):
        while m % j ==0:
            m = m / j
            prime[j]+=1
    for j in range(2,len(prime)):
        if prime[j]:
            print(j,prime[j])