z = [1,0,1]
o = [0,1,1]

def fibo(n):
    num = len(z)
    if n >= num:
        for i in range(num,n+1):
            z.append(z[i-1]+z[i-2])
            o.append(o[i-1]+o[i-2])
    print(z[n], o[n])

a = int(input())
for i in range(a):
    b = int(input())
    fibo(b)
