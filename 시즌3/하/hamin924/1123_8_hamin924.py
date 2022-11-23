def lcm(a, b) : #최소 공배수
  return int((a*b) / gcd(a, b))

def gcd(a, b) : #최대 공약수
  if a == 0 :
    return b
  else :
    return gcd(b % a, a)

T = int(input())

for _ in range(T) :
  a, b = map(int, input().split())
  print(lcm(a, b), gcd(a, b))