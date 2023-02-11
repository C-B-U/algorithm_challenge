# 1252번: 이진수 덧셈

a,b = input().split()  # 이진수를 입력받을때 int범위를 초과할 수 있으므로 우선 str형태로 입력받음
result = int(a, 2) + int(b, 2)  # 10진수 형태로 변형하여 계산 실행
result = bin(result)
print(result[2:])  # 0b~~ 형태로 나오고 있기 때문에 앞 2자리를 제외하고 출력함
