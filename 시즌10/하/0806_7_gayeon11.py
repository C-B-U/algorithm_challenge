N, M = map(int, input().split())
while True:
    if(M == 1 or M == 2):
        print("NEWBIE!")
        break
    elif(M <= N):
        print("OLDBIE!")
        break
    else:
        print("TLE!")
        break