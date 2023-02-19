# 1312번: 소수

A,B,N = map(int, input().split())

for i in range(N):  # A를 B로 나눈 나머지를 N번 반복하여 구한다.
    A = (A%B)*10  # A*10을 B로 나눴을때 몫이 A/B의 소수 첫째자리이다.
    
result = A//B 
print(result)
