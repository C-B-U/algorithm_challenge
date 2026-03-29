n, l = map(int,input().split())

spots = list(map(int,input().split()))
taping = [-1]

# 구멍들을 위치 순서대로 정렬한다.
spots.sort()

# 구멍들을 확인하면서 구멍이 있을 경우, 테이프의 길이만큼 덮은 후 taping 배열에 덮인 위치를 기록한다.
for i in range(len(spots)):
  if(taping[-1] <= spots[i]):
    taping.append(spots[i]+l)

print(len(taping)-1)
