# 가능한 일정들을 정렬한 뒤에 가장 긴 길이를 찾는다.

n = int(input())

seniors = {}
for _ in range(n):
    name, week, day, pay = input().split()
    seniors[name] = ( (int(week) * 7 + int(day)), int(pay) )

schedules = set()
for _ in range(n):
    name, money = input().split()

    if seniors[name][1] <= int(money):
        schedules.add(seniors[name][0])

schedules = sorted(schedules)
if not schedules: print(0); quit()

day = schedules[0] - 1
max_count = 0
count = 0

for event in schedules:
    if event == day + 1:
        count += 1
        max_count = max(max_count, count)
    else: count = 1
    day = event
        
print(max_count)
