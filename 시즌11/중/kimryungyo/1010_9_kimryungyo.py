# 한 노드의 진출 차수가 항상 1개이므로 딱히 그래프 탐색 알고리즘은 필요 없다.
# 풀이 : A에서 출발해 계속 다음 문자들로 넘어가면서 B가 발견된다면 T 출력.
#       사이클이 발생하는 경우 주의

N = int(input())

graph = [ -1 ] * 128
for _ in range(N):
    a, b = map(ord, input().split(" is "))
    graph[a] = b

M = int(input())
for _ in range(M):
    a, b = map(ord, input().split(" is "))

    visited = [ False ] * 128
    visited[a] = True

    while a != b:
        a = graph[a]
        if a == -1: break
        if visited[a] is True: break
        visited[a] = True

    print("T" if a == b else "F")