N=int(input())
re_N = N
cycle = 0
while True:
        a = re_N//10 #정수 앞자리
        b = re_N%10 #정수 뒷자리
        c = (a+b)%10 #더한 수의 뒷자리
        re_N = (b*10)+c #정수 뒷자리와 더한 수의 뒷자리 연결
        cycle+=1 #사이클 길이 +1
        if(re_N == N):
            break
print(cycle)