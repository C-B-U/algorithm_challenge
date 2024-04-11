'''
1.n까지 좌르륵 담긴 리스트
2.에라토스테네스의 체로 리스트에서 소수아닌애들 다 지우기
3.투포인터


'''

def dofkxhtmxpsptm(n):
    prime=[True]*(n+1)
    prime[0]=prime[1]=False
    for i in range(2,int(n/2)+1):
        if prime[i]:
            for j in range(i*i,n+1,i):
                prime[j]=False
            
    return [i for i in range(2,n+1) if prime[i]]
import sys
input=sys.stdin.readline
N=int(input())
lindex=0
rindex=0
answer=0
lst=dofkxhtmxpsptm(N)

while rindex<len(lst):
    summ=sum([lst[x] for x in range(lindex,rindex+1)])
    if summ==N:
        answer+=1
        rindex+=1
    if summ>N:
        lindex+=1
    if summ<N:
        rindex+=1
    


print(answer)
