Line = []   # 각 줄의 입력값을 리스트에 받아온다.
charac = ""   # 찾을 알파벳을 빠른 접근을 위해 변수로 지정해둔다

while True:
    Line = input()
    Line = Line.lower()    # 대소문자 구분을 편하게 하기 위해 전부 소문자로 변환한다.
    count = 0

    if(Line[0]=="#"):   # 마지막 줄일 경우에 반복을 제거한다.
        break
    else:
        charac = Line[0]

    for i in range(2,len(Line)-1):   # 리스트의 요소들을 하나씩 비교하며 count값을 증가시킨다.
        if(Line[i] == charac):
            count +=1
            
    print(charac, count)
