# [ 풀이 ]
# 1. 각 수가 딱 2개씩 존재하지 않는 경우 정리가 불가능하다.
# 2. 두 수가 같은 배열에 있다면, 둘 중 하나만 스왑해야 한다.
# 3. 두 수가 다른 배열에 있다면, 둘 다 스왑하거나 둘 다 스왑하지 않아야 한다.
# 4. 해당 조건들로 가중치 그래프를 모델링 후 그래프 탐색을 진행한다.

from collections import deque

# 입력 받기
n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# 각 수의 개수를 센 후, 2개가 아닌 경우 정리가 불가능하므로 -1 출력
counts = [0] * (n + 1)
for i in range(n):
    counts[A[i]] += 1
    counts[B[i]] += 1

for i in range(1, n + 1):
    if counts[i] != 2:
        print(-1)
        quit()

# 숫자 위치 저장
positions = [[] for _ in range(n + 1)]
for i in range(n):
    positions[A[i]].append((i, 0))
    positions[B[i]].append((i, 1))

# 그래프 생성
graph = [[] for _ in range(n)]
for value in range(1, n + 1):
    (i, arr_i), (j, arr_j) = positions[value][0], positions[value][1]
    
    # 해당 인덱스의 두 값이 같은 경우 스왑이 의미가 없으므로 무시
    if i == j:
        continue
    
    # 두 위치를 해당 위치에 해야하는 행동을 나타내는 간선으로 연결
    # 두 수가 같은 배열에 있어 두 노드가 서로 다른 행동을 해야하는 경우 간선의 가중치는 1
    # 아닌 경우 간선의 가중치는 0
    weight = 1 if arr_i == arr_j else 0
    graph[i].append((j, weight))
    graph[j].append((i, weight))

# 각 노드를 탐색하면서 스왑 여부 결정
# -1 (미방문), 0 (스왑 X), 1 (스왑 O)
swaped = [-1] * n
answer = 0

for i in range(n):
    if swaped[i] != -1: continue

    # 연결 노드가 없는 경우 넘어감
    if not graph[i]:
        swaped[i] = 0
        continue

    # BFS를 이용해 연결된 그룹들을 탐색
    queue = deque([i])
    swaped[i] = 0
    groups = []

    while queue:
        current = queue.popleft()
        groups.append(current)

        for next, weight in graph[current]:
            action = swaped[current] if weight == 0 else 1 - swaped[current]

            if swaped[next] == -1:
                swaped[next] = action
                queue.append(next)

            # 그룹 내에서 모순이 발생한 경우 정리 불가능
            elif swaped[next] != action:
                print(-1)
                quit()

    # 그룹 내에서는 모든 결정을 뒤집어도 결과가 동일하다
    # 따라서 둘 중 스왑 횟수가 적은 경우를 채택해야 한다
    # 이걸 놓쳐서 시간을 많이 소모했다..
    swaps_count = sum(swaped[node] for node in groups)
    non_swaps_count = len(groups) - swaps_count
    answer += min(swaps_count, non_swaps_count)

# 정답 출력
print(answer)