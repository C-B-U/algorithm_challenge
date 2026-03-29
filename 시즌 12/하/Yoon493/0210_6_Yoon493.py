N = int(input()) # 메뉴의 개수 N
list_A = []  # 메뉴의 가격을 저장할 리스트
total = 0   # 결제해야 하는 금액의 총액

for i in range (0, N):
	A = int(input())
	list_A.append(A)
	i += 1

M = int(input())

for j in range (0, M):
    B = int(input())
    total += list_A[B - 1]  # B-1번째 줄에는 B-1번째 코너에서 판매하는 메뉴의 가격
    j += 1

print(total)