n, m = map(int, input().rstrip().split())
graph = [i for i in range(n+1)]

def findParent(n):
  if graph[n] == n:
    return n
  stack = [n]
  while graph[n] != n:
    n = graph[n]
    stack.append(n)
  for node in stack:
    graph[node] = n
  return n

def union(graph, a, b):
  a = findParent(a)
  b = findParent(b)
  if a < b:
    graph[b] = a
  else:
    graph[a] = b

answer = []

for _ in range(m):
  check, a, b = map(int, input().rstrip().split())
  if check == 1:
    if findParent(a) == findParent(b):
      answer.append("YES")
    else:
      answer.append("NO")
  else:
    union(graph, a, b)

for i in answer:
  print(i)
