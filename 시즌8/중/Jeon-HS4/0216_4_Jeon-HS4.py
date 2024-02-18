n = int(input())
schedule = []

for i in range(n):
  a, b = map(int, input().split())
  schedule.append(a-b)

schedule.sort()

if(n%2 == 1):
  print(1)
else:
  print(abs(schedule[n//2] - schedule[(n//2)-1]) + 1)
