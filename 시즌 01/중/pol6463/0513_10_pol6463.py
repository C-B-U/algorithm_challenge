from math import gcd

n = int(input())
x = list(map(int, input().split()))
N = 1
for i in x:
    N = N * i

m = int(input())
y = list(map(int, input().split()))
M = 1
for i in y:
    M = M  * i

res = gcd(N, M)
if (res) >= 1000000000:
    print('%09d' %(res%1000000000))
else:
    print(res)