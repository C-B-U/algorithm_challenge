import datetime

today_y, today_m, today_d = map(int,input().split())
dday_y, dday_m, dday_d = map(int,input().split())

d_day = int(str(datetime.date(dday_y, dday_m, dday_d)-datetime.date(today_y, today_m, today_d)).split()[0])

# print(d_day)
over = 0 
for i in range(0,1000) :
    if i%400==0 :
        over +=366
    elif i%100==0 :
        over += 365
    elif i%4==0 :
        over += 366
    else :
        over += 365

if d_day >= over :
    print('gg')
else :
    print(f'D-{d_day}')