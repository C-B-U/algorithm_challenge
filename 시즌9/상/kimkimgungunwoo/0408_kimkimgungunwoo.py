import sys
input = sys.stdin.readline
answer=[]
while True:
    
    n, money = map(float, input().strip().split())
    n=int(n)
    
    money=int(money*100)
    if n==0 and money==0:
        break

    can=[]
    for i in range(n):
        candy_kal,candy_m=map(float,input().rstrip().rsplit())
        candy_kal,candy_m=int(candy_kal),int(candy_m*100+0.5)
        can.append([candy_kal,candy_m])
    dp=[0]*10001 #지금있는 돈으로 살 수있는 최대한의 칼로리 저장됨
    for i in range(1,money+1):  #한번의 한번의 돈 확인
        for j in range(n): #한번에 한종류의 사탕 확인   
            cam=can[j][1]
            cak=can[j][0]         
            if (i<cam):
                continue
            
            dp[i]=max(dp[i],dp[i-cam]+cak) #배낭문제의 점화식 일차식으로 변경      
    answer.append(dp[money])
    
for i in range(len(answer)):
    print(answer[i])



