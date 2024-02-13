import heapq

N = int(input())

classTime = []
for _ in range(N):
    classTime.append(list(map(int, input().split())))
classTime.sort()

timeTable = []
timeTable.append(classTime[0][1])

for i in range(1, N):
    if classTime[i][0] < timeTable[0]:
        heapq.heappush(timeTable, classTime[i][1])
    else:
        heapq.heappop(timeTable)
        heapq.heappush(timeTable, classTime[i][1])

print(len(timeTable))
