Angles=[]    # 입력값들을 배열에 저장

for i in range(3):
    Angles.append(int(input()))

if(sum(Angles)==180):
    if(len(set(Angles))==1):  # 모두 60이면 set적용 시 Angle에는 60만 남음
        print("Equilateral")
    elif(len(set(Angles))==2):  # 이등변 삼각형은 같은 각 하나가 제거되어 len == 2가 됨
        print("Isosceles")
    else:
        print("Scalene")
else:
    print("Error")
