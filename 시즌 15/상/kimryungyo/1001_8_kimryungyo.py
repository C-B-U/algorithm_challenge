N, M = map(int, input().split())
times = list(map(int, input().split()))
if N <= M: print(N); quit()

# 시각 t까지 탑승 시작한 총 인원
def check(t):
    return sum(t // a for a in times) + M

# 매개변수 탐색 - served(t) >= N 이 되는 최소 t
low, high = 0, max(times) * N
while low < high:
    mid = (low + high) // 2
    if check(mid) >= N:
        high = mid
    else:
        low = mid + 1
min_time = low  # 최소 시각

# 직전 시각까지 탄 인원
before = check(min_time - 1)

# 시각 t에 비어있는 놀이기구를 번호순으로 배정
for i, a in enumerate(times, start=1):
    if min_time % a == 0:
        before += 1
        if before == N:
            print(i)
            break