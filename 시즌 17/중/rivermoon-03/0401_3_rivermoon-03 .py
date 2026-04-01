import sys
input = sys.stdin.readline

# 1. 순서랑 상관없이 결과가 나옴.
# 2. 2번 누르게 되면 원상태.
# 3. 버튼 누르는 횟수 = 시간
# 4. 굳이 100,000개를 다 계산해야 할까?
n, m = map(int, input().split())
# 각 동작 당 드는 시간
cost = [n, n // 2, (n + 1) // 2, (n - 1) // 3 + 1 if n > 0 else 0]
possible_time = set() # 중복되는건 알아서 제외

# 모두 시도
for s1 in [0, 1]:
    for s2 in [0, 1]:
        for s3 in [0, 1]:
            for s4 in [0, 1]:
                # 0,0,0,0~1,1,1,1 (아무것도 안하던가 다 해보던가)
                total_time = (s1 * cost[0] + s2 * cost[1] + s3 * cost[2] + s4 * cost[3])
                
                # m초 이하동안에 할 수 있는것만
                if total_time <= m:
                    # 버튼 상태 계산 (10개만 해도 대충 연산 가능. n이 10보다 작으면 n개만)
                    time_limit = 10 if n > 10 else n
                    state = [] # 버튼 상태
                    
                    for i in range(1, time_limit + 1): # 버튼 i가 눌리는 횟수 계산
                        press_count = 0
                        if s1: press_count += 1               # 모든 버튼
                        if s2 and i % 2 == 0: press_count += 1 # 짝수 버튼
                        if s3 and i % 2 != 0: press_count += 1 # 홀수 버튼
                        if s4 and (i - 1) % 3 == 0: press_count += 1 # 1, 4, 7...
                        # 버튼 상태 저장.
                        state.append(press_count % 2)
                    possible_time.add(tuple(state)) # 리스트는 튜플에 못 넣는다.
print(len(possible_time))