# 백준 1110번 더하기 사이클

def next_num(N):     # 문제의 조건을 가독성을 높여 작성
    n1 = N//10
    n2 = N%10
    n3 = (n1+n2)%10
    return n2*10 + n3

N = int(input())
n = N
count = 0

while(True):       # 최소 1회 반복해야 하므로 while문 안에 break 경우를 설정
    n = next_num(n)
    count += 1
    if(N==n):
        break
        
print(count)


# 함수 사용 하지 않고, 메모리와 속도를 맞춘 방법
"""
N = int(input())
A = N
c = 0
while True:
    N = (N%10)*10 + (N//10 + N%10)%10
    c += 1
    if (A == N):
        break
print(c)
"""
