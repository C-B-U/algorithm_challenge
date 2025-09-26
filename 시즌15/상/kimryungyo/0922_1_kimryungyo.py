from collections import deque

n, d, k, c, *arr = map(int, open(0).read().split())
belt = deque(arr)

# 벨트가 순환 구조이므로 초반 k개의 요소를 뒤에 추가
if n >= k: belt.extend(arr[:k])
else: print(len(set(arr))); quit()

eats = deque()
menus = dict()

max_count = 0

while belt:
    # 벨트에서 초밥을 하나 빼고 먹을 초밥에 추가
    num = belt.popleft()
    eats.append(num)

    # 현재 먹는 초밥의 종류를 기록
    if num not in menus: menus[num] = 1
    else: menus[num] += 1

    # 초밥의 수가 k개를 넘어가면 하나 제거
    if len(eats) > k:
        out = eats.popleft()
        if menus[out] == 1: del menus[out]
        else: menus[out] -= 1

    if len(eats) == k:
        # 현재 먹는 초밥의 가지 수
        count = len(menus)

        # 쿠폰 번호의 초밥을 먹지 않은 경우 쿠폰 사용
        if c not in menus:
            count += 1

        if count > max_count:
            max_count = count

print(max_count)