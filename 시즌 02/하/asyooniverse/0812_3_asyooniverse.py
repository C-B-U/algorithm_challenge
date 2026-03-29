N = int(input())
result = 1
if N>0:
  for i in range(1, N+1):
    result = result*i
print(result)

# 16173번
# bfs, deque 써서 다시 풀어보기