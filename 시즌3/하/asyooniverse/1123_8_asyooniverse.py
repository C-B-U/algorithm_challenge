import math

for i in range(int(input())):
    a, b = map(int, input().split())
    print(math.lcm(a,b), math.gcd(a,b))