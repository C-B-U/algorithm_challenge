a, b = map(int,input().split())
buttons = [0] *a # 버튼 초기 상태

states = set()
states.add(tuple(buttons)) # 아무것도 안 누른 상태

#4가지 동작
def Actions(state,action_num,n):
    s = list(state)
    if action_num == 1:  # 모든 버튼
        indices = range(n)
    elif action_num == 2:  # 짝수 버튼
        indices = range(1, n, 2)
    elif action_num == 3:  # 홀수 버튼
        indices = range(0, n, 2)
    elif action_num == 4:  #(3k + 1)버튼
        indices = range(0, n, 3)
    time = len(list(indices)) # 걸리는시간
    for i in indices:
        s[i] ^= 1  # 토글
    return tuple(s), time

while True:
    if b != 0:
        # 16가지 조합 탐색 (각 동작 적용 여부)
        for mask in range(16):
            state = tuple([0] * a)
            total_time = 0
            for i in range(4):
                if mask & (1 << i):
                    state, time = Actions(state, i + 1, a)
                    total_time += time
            if total_time <= b:
                states.add(state)
        b = 0  # 탐색 완료 후 종료

    if b == 0:
        break
res = len(states)
print(res)
