# [ 풀이 ]
# 1. 스택을 이용해 그래프의 형태를 분석한다.
# 2. 두 노드의 최소 공통 조상을 찾기 위해 필요한 정보인
#    각 노드의 깊이와 부모 노드를 구한다.
# 3. 구한 정보를 이용해 두 노드의 최소 공통 조상을 구한다.
#    최대 노드의 수가 2000개이므로 logn 시간 복잡도를 요구하지는 않는다.

# 정보 입력
N = int(input())
binary = input()
X, Y = map(int, input().split())

# 그래프의 정보를 저장할 리스트
depths = [ None ] * N
parents = [ None ] * N
mapping = []

# 스택을 이용해 그래프 분석
stack = []
depth = 0
new_node = 0
for bit in binary:
    
    # 다음 노드에 방문하는 경우
    if bit == "0":
        # 새 노드의 번호, 깊이 및 부모 노드를 기록
        depths[new_node] = depth
        parents[new_node] = stack[-1] if stack else None
        mapping.append(new_node)

        # 스택에 노드 추가
        stack.append(new_node)

        # 다음 노드에 사용될 정보 업데이트
        new_node += 1
        depth += 1

    # 이전 노드로 돌아가는 경우
    else:
        # 스택에서 현재 노드를 제거하고 현재 노드의 번호를 기록
        node = stack.pop()
        mapping.append(node)

        # 노드의 깊이 1 감소
        depth -= 1

# 기초적인 LCA 알고리즘으로 최소 공통 조상 탐색
a, b = mapping[X-1], mapping[Y-1]
while depths[a] > depths[b]: a = parents[a]
while depths[b] > depths[a]: b = parents[b]

while a != b:
    a = parents[a]
    b = parents[b]

# 이진수에서 최소 공통 조상의 위치를 출력
i = mapping.index(a) + 1
j = mapping.index(a, i) + 1
print(i, j)