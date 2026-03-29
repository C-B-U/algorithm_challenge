import heapq
n = int(input())
subject = sorted([list(map(int, input().split())) for _ in range(n)])
classroom = []
heapq.heappush(classroom, subject[0][1])

for i in range(1, n):
    if subject[i][0] < classroom[0]:
        heapq.heappush(classroom, subject[i][1])
    else:
        heapq.heappop(classroom)
        heapq.heappush(classroom, subject[i][1])

print(len(classroom))
