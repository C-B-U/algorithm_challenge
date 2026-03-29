h,w = map(int, input().split())
result = 0

for i in range(h):  # 한줄씩 입력받기
    line = input()
    ractangle = False  # 각 칸이 도형의 내부인지 외부인지 판별
    for j in range(w):  # 한 칸마다 확인 
        if(ractangle == True):  # 만약 도형 내부라면
            if(line[j] == "."):  # . 일 경우 한칸을 차지하므로 1 추가
                result += 1
            else:  # /나 \일 경우 반칸을 차지하는 0.5를 추가하고 도형이 끝나는 지점이므로 체크
                result += 0.5
                ractangle = False
        else:  # 도형이 아닐 경우 \나 / 일 경우에 도형 내부로 진입
            if(line[j] != "."):
                result += 0.5
                ractangle = True

print(int(result))
