N = int(input())  # 동호가 저번 달에 이용한 통화의 개수
N_list = list(map(int, input().split())) # 통화시간 N개

Y = 0 # 영식 요금제
M = 0 # 민식 요금제

# 요금제 계산
for n in N_list:
	Y += (n//30 + 1)* 10  # 영식 요금제 계산
	M += (n//60 + 1)* 15  # 민식 요금제 계산

# 출력
if Y < M:
    print("Y", Y) # 영식 요금제가 더 쌀 때
elif M < Y:
    print("M", M)  # 민식 요금제가 더 쌀 때
else:
    print("Y M", Y)  # 두 요금제의 요금이 모두 같을때