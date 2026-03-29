
# A = 고정 비용, B = 가변 비용, C = 노트북 판매 가격, n = 노트북 개수
# 이익 = (1대 당 판매가 C - 1대 당 생산비용 B) * n - 고정 비용 A

A, B, C = map(int, input().split())
if B >= C:
    print(-1)
else:
    print(int(A//(C-B)+1))