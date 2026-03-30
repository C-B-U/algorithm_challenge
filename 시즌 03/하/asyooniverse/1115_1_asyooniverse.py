# 마스크와 티셔츠는 다른 색이어야 한다.
# 티셔츠와 바지 역시 다른 색이어야 한다.
# 이틀 연속으로 같은 색의 티셔츠를 입지 않는다.
# 한번 착용한 마스크, 티셔츠, 바지는 다시 사용하지 않는다.

# 마스크랑 바지는 같은색
# 적은 수에 맞춰서 계산

mask = list(map(int, input().split()))
shirt = list(map(int, input().split()))
pants = list(map(int, input().split()))
result = []

first = min(mask[0], shirt[1], pants[0])
second = min(mask[1], shirt[0], pants[1])

result.extend([first, second])
result.sort()

if result[1] - result[0] not in [0,1]:
  print(result[0]*2 + 1)
else:
  print(result[0]+result[1])