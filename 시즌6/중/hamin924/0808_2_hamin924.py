import sys
input = sys.stdin.readline

finger = int(input())    # 다친 손가락 위치
count = int(input())    # 다친 손가락의 최대 사용 횟수 

result = 0 

if finger==1:
    result = 8 * count

elif finger==5:
        result = 8 * count +4

else:
    if count % 2 == 0 :
        result = 4 * count + (finger-1)
    else:
        result = 4 * count + (5-finger)
            
print(result)           