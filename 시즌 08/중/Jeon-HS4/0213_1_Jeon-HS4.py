t = int(input())
for _ in range(t):
    n = int(input())
    fib0 = [1,0]
    fib1 = [0,1]
    if(n >=2):
      for i in range(2,n+1):
        fib0.append(fib0[i-2]+fib0[i-1])
        fib1.append(fib1[i-2]+fib1[i-1])
    print(f'{fib0[n]} {fib1[n]}')
