# 백준 11000번
# 그리드 알고리즘, 우선순위 큐

import sys
import heapq
input = sys.stdin.readline

N = int(input())
time = []

for _ in range(N):
    time.append(list(map(int,input().split(' '))))
time.sort(key=lambda x : (x[0],x[1]))

heap = [time[0][1]]
for i in range(1,N):
    if heap[0] <= time[i][0]:
        heapq.heappop(heap)
    heapq.heappush(heap,time[i][1])

print(len(heap))