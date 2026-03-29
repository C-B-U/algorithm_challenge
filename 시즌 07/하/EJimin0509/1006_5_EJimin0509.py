def gcd(a, b):
    if a < b:
        a, b = b, a
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)
    
def lcm(a, b):
    return a * b // gcd(a, b)

a, b = map(int, input().split())
print(f"{gcd(a, b)}\n{lcm(a,b)}")