# 백준 알고리즘 19944 뉴비의 기준은 뭘까? 문제

N, M = map(int, input().split())

if(M == 1 or M == 2):
    print("NEWBIE!")

elif(M <= N):
    print("OLDBIE!")

else:
    print("TLE!")