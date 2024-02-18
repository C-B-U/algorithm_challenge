def prime_factorization(n):
    i=2
    while i*i <= n:
        if n%i:
            i+=1
        
        else:
            n//=i
            print(i)
    
    if n>1:
        print(n)


n=int(input())
prime_factorization(n)
