import datetime

now_year, now_month, now_day = map(int, input().split())
target_year, target_month, target_day = map(int, input().split())

d_day = (datetime.date(target_year, target_month, target_day) - datetime.date(now_year, now_month, now_day)).days

# deadline = (datetime.date(now_year+1000, now_month, now_day) - datetime.date(now_year, now_month, now_day)).days
deadline = 0
for i in range(now_year, now_year+1000):
    if i % 400 == 0:
        deadline += 366
    elif i % 100 == 0:
        deadline += 365
    elif i % 4 == 0:
        deadline += 366
    else:
        deadline += 365

if d_day >= deadline:
    print("gg")
else:
    print(f"D-{d_day}")