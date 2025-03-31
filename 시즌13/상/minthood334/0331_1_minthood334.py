#메모리 낭비가 심한 코드여서 나중에 dictionary를 사용하여 index를 저장하면 고칠 수 있다.
import sys

n, m = map(int, sys.stdin.readline().split())
energy = [int(sys.stdin.readline()) for _ in range(n)]
energy.sort()
start = energy[0]
graph = [[] for _ in range(energy[-1]+1)]

for _ in range(m):
    proton = int(sys.stdin.readline())
    for eg in energy:
        if eg - proton in energy:
            graph[eg].append(eg - proton)
        if eg + proton in energy:
            graph[eg].append(eg + proton)

dp = [[0, 0] for _ in range(energy[-1]+1)]

visited = [False for _ in range(energy[-1]+1)]
visited[start] = True

for eg in energy:
    dp[eg][1] = eg

'''
문제를 풀 때 난항을 겪었는데,

"또한 원자가 어떤 특정 에너지 상태(A)에서 다른 에너지 상태(B)로 변할 수 있는 방법은 한 가지 뿐이고,
이 방법을 역으로 적용(양성자를 받아들인 경우는 양성자를 내쏘고,
양성자를 내쏘는 경우는 양성자를 받아들임)하면 B에서 A로도 상태가 변할 수 있음을 알게 되었다."

라는 문장으로 한 상태로 변할 수 있는 양성자의 개수는 오직 하나라는 것을 알게 되었으며,
이를 통해 한 노드가 여러 가중치를 가진 간선은 없는 것으로 판단됐다.

따라서 한 노드에 여러 가중치를 가진 간선이 있다는 예시는 제외하고 dp로 풀었다.

"컨테이너 안에 들어간 원자들이 서로 같은 에너지 상태에 있거나,
어떤 한 개의 원자가 한 개의 양성자를 받아들이거나 내쏘아서 다른 원자와 같은 에너지 상태에 도달할 수 있다면,
이 경우는 실험에서 위험이 발생할 수 있다."

에서 한 노드가 선택되면, 간선으로 연결된 노드들은 켜질 수 없다는 점을 이용하여
dp[x][0]가 꺼진거, dp[x][1]가 켜진것으로 설정하고,
켜졌을 땐 다음 노드가 무조건 꺼져야 하므로 꺼진 값을 합연산 하고,
꺼졌을 땐 다음 노드가 꺼지든 켜지든 상관 없으므로 둘중에 큰 값을 합연산 하는 점화식을 세웠다.
'''
def dfs(x):
    for next_node in graph[x]:
        if visited[next_node]:
            continue
        visited[next_node] = True
        dfs(next_node)
        dp[x][0] += max(dp[next_node][0], dp[next_node][1])
        dp[x][1] += dp[next_node][0]

dfs(start)

print(max(dp[start][0], dp[start][1]))
